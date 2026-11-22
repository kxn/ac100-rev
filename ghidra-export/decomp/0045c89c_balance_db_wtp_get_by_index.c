// func balance_db_wtp_get_by_index @ 0045c89c size=1

undefined4 * balance_db_wtp_get_by_index(uint param_1,void *param_2)

{
  int iVar1;
  undefined4 *__src;
  
  if ((((balance_com == (uint *)0x0) || (param_2 == (void *)0x0)) || (balance_wtp_array == 0)) ||
     (*balance_com <= param_1)) {
    __src = (undefined4 *)0x0;
    if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: inputs error\r\n","balance_db_wtp_get_by_index",0x515);
    }
  }
  else {
    FUN_004082d0(balance_db_mutex,0xffffffff);
    __src = (undefined4 *)(balance_wtp_array + param_1 * 0x14);
    if (__src[1] == 0) {
      __src = (undefined4 *)0x0;
      FUN_00407f30(balance_db_mutex);
    }
    else {
      memcpy(param_2,__src,0x14);
      if ((g_balance_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[BALANCE_DEBUG](%32s) %05d: get wtp[%d](%02x:%02x:%02x:%02x:%02x:%02x) by index(%d) successed.\r\n"
               ,"balance_db_wtp_get_by_index",0x524,*__src,(uint)*(byte *)(__src + 2),
               (uint)*(byte *)((int)__src + 9),(uint)*(byte *)((int)__src + 10),
               (uint)*(byte *)((int)__src + 0xb),(uint)*(byte *)(__src + 3),
               (uint)*(byte *)((int)__src + 0xd),param_1);
      }
      FUN_00407f30(balance_db_mutex);
    }
  }
  return __src;
}

