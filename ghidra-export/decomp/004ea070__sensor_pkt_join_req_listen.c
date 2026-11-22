// func _sensor_pkt_join_req_listen @ 004ea070 size=424

undefined4 _sensor_pkt_join_req_listen(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  char *__format;
  void *__src;
  undefined4 uVar4;
  int iVar5;
  undefined1 auStack_3b8 [8];
  undefined4 local_3b0 [46];
  undefined1 auStack_2f8 [16];
  undefined2 local_2e8;
  int local_2e4;
  
  memset(auStack_2f8,0,0x2d8);
  memset(auStack_3b8,0,0xc0);
  piVar1 = (int *)cw_msg_ele_val_get(param_3,0x21);
  if ((piVar1 == (int *)0x0) || (*piVar1 == 0)) {
    iVar2 = apmngr_db_entry_get_by_mac(param_2,auStack_2f8);
    if ((iVar2 == 0) &&
       ((local_2e4 == 7 &&
        (pbVar3 = (byte *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x8c), pbVar3 != (byte *)0x0))))
    {
      iVar2 = 0;
      for (iVar5 = 0; iVar5 < (int)(uint)*pbVar3; iVar5 = (int)(short)((short)iVar5 + 1)) {
        __src = (void *)(*(int *)(pbVar3 + 4) + iVar5 * 0x20);
        if ((*(uint *)((int)__src + 0xc) & 0x60) != 0) {
          if (0xf < iVar2) {
            if (sensor_err_switch == '\0') {
              return 0;
            }
            __format = "[SENSOR_ERROR]%s()/%d Too many vap info.\n";
            uVar4 = 0x1b8;
            goto LAB_004ea1d0;
          }
          memcpy(auStack_3b8 + iVar2 * 0xc,__src,6);
          local_3b0[iVar2 * 3] = *(undefined4 *)(*(int *)(pbVar3 + 4) + iVar5 * 0x20 + 0xc);
          iVar2 = (int)(short)((short)iVar2 + 1);
        }
      }
      sensor_db_update_vap_info(local_2e8,iVar2,auStack_3b8);
    }
  }
  else if (sensor_debug_switch != '\0') {
    __format = "[SENSOR_DEBUG]%s()/%d No need to handle because join failed.\n";
    uVar4 = 0x1ac;
LAB_004ea1d0:
    printf(__format,"_sensor_pkt_join_req_listen",uVar4);
  }
  return 0;
}

