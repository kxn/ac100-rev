// func radius_result_check_register @ 0044606c size=272

undefined4 radius_result_check_register(void *param_1)

{
  void *__s;
  char *__format;
  undefined4 uVar1;
  
  if ((param_1 == (void *)0x0) || (*(int *)((int)param_1 + 0x20) == 0)) {
    if (radius_err_switch == 0) {
      return 0xffffffff;
    }
    uVar1 = 0x13b5;
    __format = "[RADIUS_ERR]%s()/%d Para is invalid.\n";
  }
  else {
    __s = (void *)uac_mem_malloc_my(0x30,0x13b9);
    if (__s != (void *)0x0) {
      memset(__s,0,0x30);
      memcpy((void *)((int)__s + 0xc),param_1,0x24);
      uac_list_insert_last(&g_radius_result_check_list,__s);
      return 0;
    }
    if (radius_err_switch == 0) {
      return 0xffffffff;
    }
    uVar1 = 0x13bc;
    __format = "[RADIUS_ERR]%s()/%d Memory is not enough.\n";
  }
  printf(__format,"radius_result_check_register",uVar1);
  return 0xffffffff;
}

