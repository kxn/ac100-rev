// func _wlan_caps_calculate @ 0048ab30 size=668

undefined4 _wlan_caps_calculate(int param_1,int param_2,int param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_70 [8];
  char local_68;
  char local_67;
  byte local_66;
  
  memset(auStack_70,0,0x54);
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    return 0xffffffff;
  }
  if (param_4 == (undefined1 *)0x0) {
    return 0xffffffff;
  }
  if (param_3 == 0) {
    return 0xffffffff;
  }
  uVar1 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 6),*(undefined1 *)(param_1 + 8));
  iVar2 = rdmngr_db_rd_entry_get(uVar1,auStack_70);
  if (iVar2 != 0) {
    if (wsta_roam_strategy_switch == '\0') {
      return 0xffffffff;
    }
    printf("[WSTA_ROAM_STRATEGY]%s()/%d Get rd entry failed.\n","_wlan_caps_calculate",0x21f);
    return 0xffffffff;
  }
  iVar5 = param_3 + 0x218;
  iVar2 = apdb_get_max_tx_stream_by_id
                    (*(undefined4 *)(param_3 + 0x40),iVar5,*(undefined1 *)(param_1 + 8),
                     (int)local_68);
  param_4[1] = (char)iVar2;
  if (0xf < iVar2 - 1U) {
    if (wsta_roam_strategy_switch == '\0') {
      param_4[1] = 2;
    }
    else {
      printf("[WSTA_ROAM_STRATEGY]%s()/%d Get radio nss failed, set to default %d.\n",
             "_wlan_caps_calculate",0x226,2);
      param_4[1] = 2;
    }
  }
  switch(local_67 + '\x01') {
  case '\0':
    iVar2 = apdb_support_11ax_by_id
                      (*(undefined4 *)(param_3 + 0x40),iVar5,*(undefined1 *)(param_1 + 8),
                       (int)local_68);
    uVar3 = 3;
    if (iVar2 == 0) {
      iVar2 = apdb_support_11ac_by_id
                        (*(undefined4 *)(param_3 + 0x40),iVar5,*(undefined1 *)(param_1 + 8),
                         (int)local_68);
      if (iVar2 != 0) goto switchD_0048ad08_caseD_9;
      uVar3 = 1;
    }
    break;
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x06':
    param_4[2] = 0;
    goto LAB_0048ac6c;
  case '\x04':
  case '\x05':
  case '\a':
  case '\b':
switchD_0048ad08_caseD_4:
    uVar3 = 1;
    break;
  case '\t':
  case '\n':
switchD_0048ad08_caseD_9:
    uVar3 = 2;
    break;
  case '\v':
  case '\f':
    uVar3 = 3;
    break;
  default:
    uVar3 = 1;
    if (wsta_roam_strategy_switch != '\0') {
      printf("[WSTA_ROAM_STRATEGY]%s()/%d Rd mode[%d] not recognized, use ESTIMATE_PHYMODE_HT.\n",
             "_wlan_caps_calculate",0x254);
      goto switchD_0048ad08_caseD_4;
    }
  }
  param_4[2] = uVar3;
LAB_0048ac6c:
  uVar4 = (uint)local_66;
  if (uVar4 == 2) {
    uVar4 = (uint)*(ushort *)(param_2 + 10);
  }
  if (uVar4 == 1) {
    *param_4 = 1;
    goto LAB_0048acc8;
  }
  if (uVar4 < 2) {
    if (uVar4 == 0) {
      *param_4 = 0;
      goto LAB_0048acc8;
    }
LAB_0048aca8:
    if (wsta_roam_strategy_switch == '\0') {
      iVar2 = *(int *)(param_2 + 4);
    }
    else {
      printf("[WSTA_ROAM_STRATEGY]%s()/%d Rd bw[%d] not recognized, judge it by freq_type[%d].\n",
             "_wlan_caps_calculate",0x269,uVar4,*(undefined4 *)(param_2 + 4));
      iVar2 = *(int *)(param_2 + 4);
    }
    if (iVar2 != 1) {
      *param_4 = 0;
      goto LAB_0048acc8;
    }
  }
  else if (uVar4 != 3) {
    if (uVar4 == 5) {
      *param_4 = 3;
      goto LAB_0048acc8;
    }
    goto LAB_0048aca8;
  }
  *param_4 = 2;
LAB_0048acc8:
  param_4[3] = 0;
  param_4[4] = (char)*(undefined2 *)(param_2 + 0xc);
  return 0;
}

