// func wsta_db_sta_update_ip @ 00638a90 size=908

undefined4
wsta_db_sta_update_ip
          (char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
          ,undefined4 param_6)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined1 local_b4 [28];
  undefined1 auStack_98 [24];
  undefined1 auStack_80 [108];
  
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  if (((((*param_1 == '\0') && (param_1[1] == '\0')) && (param_1[2] == '\0')) &&
      ((param_1[3] == '\0' && (param_1[4] == '\0')))) && (param_1[5] == '\0')) {
    if (g_wsta_warning == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("<wsta>[warning]%s(): %d  -> invalid mac addr!\r\n","wsta_db_sta_update_ip",0x915);
    return 0xffffffff;
  }
  memset(auStack_98,0,0x80);
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  iVar2 = FUN_00407fa0(DAT_007cc72c,param_1);
  pcVar6 = (char *)(iVar2 + 6);
  if (iVar2 == 0) {
    pcVar6 = param_1;
  }
  bVar1 = false;
  iVar2 = FUN_00407fa0(DAT_007cc6cc,pcVar6);
  if (iVar2 == 0) goto LAB_00638b4c;
  if (local_res4._0_1_ == '\x01') {
    iVar3 = FUN_00407eb0(*(undefined4 *)(iVar2 + 0x3c),*(undefined4 *)(iVar2 + 0x40),
                         *(undefined4 *)(iVar2 + 0x44),*(undefined4 *)(iVar2 + 0x48),
                         *(undefined4 *)(iVar2 + 0x4c));
    uVar4 = 0;
    if (iVar3 != 0) {
      for (; uVar4 < 0x14; uVar4 = uVar4 + 1) {
        local_b4[uVar4] = *(undefined1 *)((int)&local_res4 + uVar4);
      }
      iVar3 = FUN_004085c0(*(undefined4 *)(iVar2 + 0x3c),*(undefined4 *)(iVar2 + 0x40),
                           *(undefined4 *)(iVar2 + 0x44),*(undefined4 *)(iVar2 + 0x48),
                           *(undefined4 *)(iVar2 + 0x4c));
      if ((iVar3 == 0) && (iVar3 = FUN_00407fa0(DAT_007cc6d0,iVar2 + 0x3c), iVar2 == iVar3)) {
        FUN_00407f40(DAT_007cc6d0,iVar2);
      }
    }
    memcpy((void *)(iVar2 + 0x3c),&local_res4,0x14);
    iVar3 = FUN_00407eb0(local_res4,local_res8,local_resc,param_5,param_6);
    if (iVar3 == 0) {
      *(undefined1 *)(iVar2 + 0x3c) = 0;
    }
    else {
      iVar3 = FUN_00407fa0(DAT_007cc6d0,&local_res4);
      uVar5 = DAT_007cc6d0;
      if (iVar3 != 0) {
        if (iVar3 == iVar2) goto LAB_00638b3c;
        FUN_00407f40(DAT_007cc6d0,iVar3);
        uVar5 = DAT_007cc6d0;
      }
LAB_00638cec:
      FUN_00408380(uVar5,iVar2);
    }
  }
  else if (local_res4._0_1_ == '\x02') {
    iVar3 = FUN_00407eb0(*(undefined4 *)(iVar2 + 0x50),*(undefined4 *)(iVar2 + 0x54),
                         *(undefined4 *)(iVar2 + 0x58),*(undefined4 *)(iVar2 + 0x5c),
                         *(undefined4 *)(iVar2 + 0x60));
    uVar4 = 0;
    if (iVar3 != 0) {
      for (; uVar4 < 0x14; uVar4 = uVar4 + 1) {
        local_b4[uVar4] = *(undefined1 *)((int)&local_res4 + uVar4);
      }
      iVar3 = FUN_004085c0(*(undefined4 *)(iVar2 + 0x50),*(undefined4 *)(iVar2 + 0x54),
                           *(undefined4 *)(iVar2 + 0x58),*(undefined4 *)(iVar2 + 0x5c),
                           *(undefined4 *)(iVar2 + 0x60));
      if ((iVar3 == 0) && (iVar3 = FUN_00407fa0(DAT_007cc6d4,iVar2 + 0x50), iVar2 == iVar3)) {
        FUN_00407f40(DAT_007cc6d4,iVar2);
      }
    }
    memcpy((void *)(iVar2 + 0x50),&local_res4,0x14);
    iVar3 = FUN_00407eb0(local_res4,local_res8,local_resc,param_5,param_6);
    if (iVar3 != 0) {
      iVar3 = FUN_00407fa0(DAT_007cc6d4,&local_res4);
      uVar5 = DAT_007cc6d4;
      if (iVar3 != 0) {
        if (iVar3 == iVar2) goto LAB_00638b3c;
        FUN_00407f40(DAT_007cc6d4,iVar3);
        uVar5 = DAT_007cc6d4;
      }
      goto LAB_00638cec;
    }
    *(undefined1 *)(iVar2 + 0x50) = 0;
  }
LAB_00638b3c:
  bVar1 = true;
  memcpy(auStack_80,(void *)(iVar2 + 0x18),0x68);
LAB_00638b4c:
  FUN_00407f30(DAT_007cc6bc);
  if (bVar1) {
    _uac_wstation_do_event(2,auStack_98);
  }
  return 0;
}

