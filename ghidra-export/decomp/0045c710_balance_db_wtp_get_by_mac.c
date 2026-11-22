// func balance_db_wtp_get_by_mac @ 0045c710 size=396

undefined4 * balance_db_wtp_get_by_mac(byte *param_1,void *param_2)

{
  undefined4 *__src;
  int iVar1;
  
  if (((param_1 == (byte *)0x0) || (param_2 == (void *)0x0)) || (balance_wtp_hash == 0)) {
    __src = (undefined4 *)0x0;
    if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: input error\r\n","balance_db_wtp_get_by_mac",0x4eb);
    }
  }
  else {
    FUN_004082d0(balance_db_mutex,0xffffffff);
    __src = (undefined4 *)FUN_00407fa0(balance_wtp_hash,param_1);
    if (((__src != (undefined4 *)0x0) && (memcpy(param_2,__src,0x14), g_balance_debug != 0)) &&
       (iVar1 = is_target_debug_ap(balance_db_mutex), iVar1 != 0)) {
      printf("[BALANCE_DEBUG](%32s) %05d: get wtp[%d](%02x:%02x:%02x:%02x:%02x:%02x) by mac(%02x:%02x:%02x:%02x:%02x:%02x) successed.\r\n"
             ,"balance_db_wtp_get_by_mac",0x4f9,*__src,(uint)*(byte *)(__src + 2),
             (uint)*(byte *)((int)__src + 9),(uint)*(byte *)((int)__src + 10),
             (uint)*(byte *)((int)__src + 0xb),(uint)*(byte *)(__src + 3),
             (uint)*(byte *)((int)__src + 0xd),(uint)*param_1,(uint)param_1[1],(uint)param_1[2],
             (uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
    }
    FUN_00407f30(balance_db_mutex);
  }
  return __src;
}

