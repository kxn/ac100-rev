// func _uac_wserv_ap_model_update_cb @ 005d83a8 size=480

undefined4 _uac_wserv_ap_model_update_cb(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  short sVar5;
  uint uVar6;
  char *__format;
  undefined4 uVar7;
  undefined4 uVar8;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (g_wserv_debug == 0) {
    iVar2 = *(int *)(param_1 + 0x14);
  }
  else {
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x14);
    }
    else {
      printf("<wserv>[debug]%s(): %d  -> _uac_wserv_ap_model_update_cb() begin, ap_id=%d, cap_id %d \r\n"
             ,"_uac_wserv_ap_model_update_cb",0x10fc,(uint)*(ushort *)(param_1 + 0x10),
             (int)*(short *)(param_1 + 0x18));
      iVar2 = *(int *)(param_1 + 0x14);
    }
  }
  if (((iVar2 == 4) || (iVar2 == 8)) || (iVar2 == 6)) {
    sVar5 = *(short *)(param_1 + 0x18);
LAB_005d842c:
    if (sVar5 != -1) {
      iVar2 = apmngr_db_get_ap_max();
      uVar3 = apmngr_db_get_ap_max();
      iVar2 = FUN_004082a0((iVar2 >> 5) + (uint)((uVar3 & 0x1f) != 0),4,0x1101);
      if (iVar2 == 0) {
        uVar8 = 0xffffffff;
        if (g_wserv_error == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        __format = "<wserv>[error]%s(): %d  -> wserv_calloc() fail\r\n";
        uVar7 = 0x1104;
        goto LAB_005d8504;
      }
      wserv_db_ap_sync_bind_list
                (*(undefined2 *)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x10),_uac_wserv_add_cb,
                 _uac_wserv_del_cb,0,0);
      uVar6 = *(ushort *)(param_1 + 0x10) & 0x1f;
      puVar4 = (uint *)(iVar2 + (uint)(*(ushort *)(param_1 + 0x10) >> 5) * 4);
      uVar3 = *puVar4;
      bVar1 = ((int)uVar3 >> uVar6 & 1U) == 0;
      if (bVar1) {
        *puVar4 = uVar3 | 1 << uVar6;
      }
      _uac_wserv_update_aps_md5(iVar2,bVar1);
      FUN_00407df0(iVar2);
    }
  }
  else if (iVar2 == 5) {
    sVar5 = *(short *)(param_1 + 0x18);
    goto LAB_005d842c;
  }
  uVar8 = 0;
  if (g_wserv_debug == 0) {
    return 0;
  }
  iVar2 = is_target_debug_ap();
  if (iVar2 == 0) {
    return 0;
  }
  __format = "<wserv>[debug]%s(): %d  -> _uac_wserv_ap_model_update_cb() success.\r\n";
  uVar7 = 0x111b;
LAB_005d8504:
  printf(__format,"_uac_wserv_ap_model_update_cb",uVar7);
  return uVar8;
}

