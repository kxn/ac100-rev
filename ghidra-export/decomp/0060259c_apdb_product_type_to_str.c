// func apdb_product_type_to_str @ 0060259c size=148

undefined4 apdb_product_type_to_str(void *param_1,int param_2)

{
  size_t __n;
  char *__s;
  
  __s = *(char **)(&DAT_00701f18 + param_2 * 4);
  __n = strlen(__s);
  memcpy(param_1,__s,__n);
  if (apdb_debug_switch != 0) {
    printf("[APDB_DEBUG]%s()/line %d : apdb pruduct type:%d,product type str:%s\n",
           "apdb_product_type_to_str",0x1a41,param_2,param_1);
  }
  return 0;
}

