// func _uac_wserv_ap_cap_change_cb @ 005d8588 size=496

undefined4 _uac_wserv_ap_cap_change_cb(uint param_1,int param_2)

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
  
  if (param_2 == 0) {
    return 0xffffffff;
  }
  if (g_wserv_debug == 0) {
    iVar2 = *(int *)(param_2 + 0x14);
  }
  else {
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_2 + 0x14);
    }
    else {
      printf("<wserv>[debug]%s(): %d  -> _uac_wserv_ap_cap_change_cb() begin, ap_id=%d, cap_id from %d to %d.\r\n"
             ,"_uac_wserv_ap_cap_change_cb",0x10ce,(uint)*(ushort *)(param_2 + 0x10),
             param_1 & 0xffff,(int)*(short *)(param_2 + 0x18));
      iVar2 = *(int *)(param_2 + 0x14);
    }
  }
  if (((iVar2 == 4) || (iVar2 == 8)) || (iVar2 == 6)) {
    sVar5 = *(short *)(param_2 + 0x18);
LAB_005d8618:
    if (sVar5 != -1) {
      iVar2 = apmngr_db_get_ap_max();
      uVar3 = apmngr_db_get_ap_max();
      iVar2 = FUN_004082a0((iVar2 >> 5) + (uint)((uVar3 & 0x1f) != 0),4,0x10d3);
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
        uVar7 = 0x10d6;
        goto LAB_005d86f0;
      }
      wserv_db_ap_sync_bind_list
                (*(undefined2 *)(param_2 + 0x18),*(undefined2 *)(param_2 + 0x10),_uac_wserv_add_cb,
                 _uac_wserv_del_cb,0,0);
      uVar6 = *(ushort *)(param_2 + 0x10) & 0x1f;
      puVar4 = (uint *)(iVar2 + (uint)(*(ushort *)(param_2 + 0x10) >> 5) * 4);
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
    sVar5 = *(short *)(param_2 + 0x18);
    goto LAB_005d8618;
  }
  uVar8 = 0;
  if (g_wserv_debug == 0) {
    return 0;
  }
  iVar2 = is_target_debug_ap();
  if (iVar2 == 0) {
    return 0;
  }
  __format = "<wserv>[debug]%s(): %d  -> _uac_wserv_ap_cap_change_cb() success.\r\n";
  uVar7 = 0x10ed;
LAB_005d86f0:
  printf(__format,"_uac_wserv_ap_cap_change_cb",uVar7);
  return uVar8;
}

