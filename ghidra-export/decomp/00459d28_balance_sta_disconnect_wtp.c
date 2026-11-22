// func balance_sta_disconnect_wtp @ 00459d28 size=1

undefined4 balance_sta_disconnect_wtp(byte *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 == (byte *)0x0) || (param_2 == 0)) {
    uVar3 = 0xffffffff;
    if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: inputs error.\r\n","balance_db_sta_delete",0x5ee);
    }
  }
  else {
    FUN_004082d0(balance_db_mutex,0xffffffff);
    iVar1 = FUN_00407fa0(balance_wtp_hash,param_2);
    if ((((iVar1 != 0) && (*(int *)(iVar1 + 0x10) != 0)) &&
        (*(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1, g_balance_debug != 0)) &&
       (iVar2 = is_target_debug_ap(balance_db_mutex), iVar2 != 0)) {
      printf("[BALANCE_DEBUG](%32s) %05d: Decremnt station of wtp(%02x:%02x:%02x:%02x:%02x:%02x) by mac(%02x:%02x:%02x:%02x:%02x:%02x) successed, sta_cnt=%u.\r\n"
             ,"balance_db_sta_delete",0x5fb,(uint)*(byte *)(iVar1 + 8),(uint)*(byte *)(iVar1 + 9),
             (uint)*(byte *)(iVar1 + 10),(uint)*(byte *)(iVar1 + 0xb),(uint)*(byte *)(iVar1 + 0xc),
             (uint)*(byte *)(iVar1 + 0xd),(uint)*param_1,(uint)param_1[1],(uint)param_1[2],
             (uint)param_1[3],(uint)param_1[4],(uint)param_1[5],*(undefined4 *)(iVar1 + 0x10));
    }
    uVar3 = 0;
    FUN_00407f30(balance_db_mutex);
  }
  return uVar3;
}

