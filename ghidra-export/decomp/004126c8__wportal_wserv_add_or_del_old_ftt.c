// func _wportal_wserv_add_or_del_old_ftt @ 004126c8 size=440

undefined4 _wportal_wserv_add_or_del_old_ftt(int param_1)

{
  undefined4 uVar1;
  undefined *__src;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 local_3f8;
  undefined4 local_3f4;
  undefined4 local_3f0;
  undefined4 local_3ec;
  undefined4 local_3e8;
  undefined1 auStack_3e4 [152];
  undefined4 local_34c;
  int local_348;
  undefined4 local_32c;
  undefined4 local_328;
  undefined4 local_314;
  undefined1 auStack_2a0 [640];
  
  memset(auStack_3e4,0,0x144);
  local_3f8 = 0;
  local_3f4 = 0;
  local_3f0 = 0;
  local_3ec = 0;
  local_3e8 = 0;
  memset(auStack_2a0,0,0x280);
  iVar3 = cloud_server_num;
  if (param_1 != 1) {
    iVar3 = old_cloud_server_num;
  }
  if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d is_add:%d server_num:%d \n","_wportal_wserv_add_or_del_old_ftt",
           0x1ff5,param_1,iVar3);
  }
  memset(auStack_2a0,0,0x280);
  if (param_1 == 1) {
    __src = &cloud_server_ip;
  }
  else {
    __src = &cloud_server_old_ip;
  }
  memcpy(auStack_2a0,__src,0x280);
  uVar1 = 7;
  if (param_1 == 1) {
    uVar1 = 6;
  }
  puVar4 = auStack_2a0;
  for (iVar2 = 0; iVar2 < iVar3; iVar2 = iVar2 + 1) {
    local_3f8 = 0;
    local_3f4 = 0;
    local_3f0 = 0;
    local_3ec = 0;
    local_3e8 = 0;
    FUN_0051a7a8(puVar4,&local_3f8);
    memset(auStack_3e4,0,0x144);
    local_34c = 1;
    local_314 = 6;
    local_348 = g_default_cloud_free_id_begin + iVar2;
    local_32c = local_3f4;
    local_328 = 0xffffffff;
    _wportal_update_free_strategy_to_ap(auStack_3e4,uVar1);
    puVar4 = puVar4 + 0x28;
  }
  return 0;
}

