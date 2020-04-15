#include "hash_map.h"
#include "unity.h"
#include <stdlib.h>

#define M 5

int * new_int(int x){
  int * ris = (int *) malloc (sizeof(int));
  *ris = x;
  return ris;
}

int hash_function(int * key){
  return *key % M;
}

int compare_keys(int * key_one, int * key_two){
  return *key_one - *key_two;
}

HashMap * create_test_object(){
  HashMap * hash = HashMap_new((HashFunction) hash_function, (KeyCompare) compare_keys, M);
  
  HashMap_insert(hash, new_int(2),new_int(30));
  HashMap_insert(hash, new_int(7),new_int(40));
  HashMap_insert(hash, new_int(8),new_int(50));
  
  return hash;
}

static void hash_map_zero_size_table(){
  HashMap * hash = HashMap_new((HashFunction) hash_function, (KeyCompare) compare_keys, M);
  
  TEST_ASSERT_TRUE(HashMap_is_empty(hash)); 
  TEST_ASSERT_EQUAL(0, HashMap_number_associations(hash));

  HashMap_free(hash);
}

static void hash_map_insert_test(){
  HashMap * hash = create_test_object();

  HashMap_insert(hash, new_int(9),new_int(60));
  HashMap_insert(hash, new_int(12),new_int(70));

  TEST_ASSERT_TRUE(HashMap_key_is_present(hash,new_int(2)));
  TEST_ASSERT_TRUE(HashMap_key_is_present(hash,new_int(7)));
  TEST_ASSERT_TRUE(HashMap_key_is_present(hash,new_int(8)));
  TEST_ASSERT_TRUE(HashMap_key_is_present(hash,new_int(9)));
  TEST_ASSERT_TRUE(HashMap_key_is_present(hash,new_int(12)));

  TEST_ASSERT_NULL(HashMap_get_value(hash,new_int(0)));
  TEST_ASSERT_NULL(HashMap_get_value(hash,new_int(1)));
  TEST_ASSERT_NULL(HashMap_get_value(hash,new_int(5)));

  TEST_ASSERT_EQUAL(30,*(int*) HashMap_get_value(hash,new_int(2)));
  TEST_ASSERT_EQUAL(40,*(int *) HashMap_get_value(hash,new_int(7)));
  TEST_ASSERT_EQUAL(50,*(int *) HashMap_get_value(hash,new_int(8)));  
  TEST_ASSERT_EQUAL(60,*(int *) HashMap_get_value(hash,new_int(9)));
  TEST_ASSERT_EQUAL(70,*(int *) HashMap_get_value(hash,new_int(12)));

  TEST_ASSERT_EQUAL(5, HashMap_number_associations(hash));

  HashMap_free(hash);
}

static void hash_map_delete_test(){
  HashMap * hash = create_test_object();

  HashMap_delete(hash,new_int(7));
  HashMap_delete(hash,new_int(8));
  HashMap_delete(hash,new_int(10));

  TEST_ASSERT_FALSE(HashMap_key_is_present(hash,new_int(7)));
  TEST_ASSERT_FALSE(HashMap_key_is_present(hash,new_int(8)));
  TEST_ASSERT_TRUE(HashMap_key_is_present(hash,new_int(2)));

  TEST_ASSERT_EQUAL(1, HashMap_number_associations(hash));

  HashMap_free(hash);
}

static void hash_map_delete_all_test(){
  HashMap * hash = create_test_object();

  HashMap_delete_all_associations(hash);

  TEST_ASSERT_EQUAL(0, HashMap_number_associations(hash));
  TEST_ASSERT_TRUE(HashMap_is_empty(hash));

  TEST_ASSERT_FALSE(HashMap_key_is_present(hash,new_int(2)));
  TEST_ASSERT_FALSE(HashMap_key_is_present(hash,new_int(3)));
  TEST_ASSERT_NULL(HashMap_get_value(hash,new_int(2)));
  TEST_ASSERT_NULL(HashMap_get_value(hash,new_int(3)));

  HashMap_free(hash);
}

static void hash_map_all_key_test(){
  HashMap * hash = create_test_object();

  int ** keys = (void*) HashMap_all_keys(hash);

  TEST_ASSERT_EQUAL(7,*(int*)keys[0]);
  TEST_ASSERT_EQUAL(2,*(int*)keys[1]);
  TEST_ASSERT_EQUAL(8,*(int*)keys[2]);

  free(keys);
  free(hash);
}

int main(){

  UNITY_BEGIN();

  RUN_TEST(hash_map_zero_size_table);
  RUN_TEST(hash_map_insert_test);
  RUN_TEST(hash_map_delete_test);
  RUN_TEST(hash_map_delete_all_test);
  RUN_TEST(hash_map_all_key_test);

  UNITY_END();

}