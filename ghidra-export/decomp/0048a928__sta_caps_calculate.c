// func _sta_caps_calculate @ 0048a928 size=520

undefined4 _sta_caps_calculate(int param_1,int param_2,undefined1 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined1 auStack_1d0 [17];
  char local_1bf;
  char local_1be;
  uint local_1b8;
  uint local_1b4;
  
  memset(auStack_1d0,0,0x1c0);
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (param_3 == (undefined1 *)0x0) {
    return 0xffffffff;
  }
  iVar3 = stats_db_sta_get(param_1,auStack_1d0,0);
  if (iVar3 != 0) {
    if (wsta_roam_strategy_switch != '\0') {
      printf("[WSTA_ROAM_STRATEGY]%s()/%d Staion statistics not ready, use default.\n",
             "_sta_caps_calculate",0x1d9);
    }
LAB_0048a98c:
    uVar4 = 1;
    if (param_2 == 1) {
      uVar4 = 2;
      uVar5 = 9;
      *param_3 = 2;
    }
    else {
      uVar5 = 7;
      *param_3 = 0;
    }
    param_3[1] = uVar4;
    param_3[2] = uVar4;
    param_3[3] = uVar5;
    param_3[4] = 0;
    return 0;
  }
  if (param_2 == 0) {
    iVar3 = (int)local_1bf;
  }
  else if (param_2 == 1) {
    iVar3 = (int)local_1be;
    local_1b8 = local_1b4;
  }
  else {
    iVar3 = 0;
    local_1b8 = 0;
  }
  uVar6 = local_1b8 & 0xf;
  param_3[1] = (char)uVar6;
  uVar1 = (local_1b8 << 0x18) >> 0x1c;
  uVar2 = (local_1b8 << 0x10) >> 0x18;
  param_3[2] = (byte)local_1b8 >> 4;
  param_3[3] = (char)(local_1b8 >> 8);
  if (((0xf < uVar6 - 1) || (4 < uVar1)) || (0xd < uVar2)) {
    if (wsta_roam_strategy_switch != '\0') {
      printf("[WSTA_ROAM_STRATEGY]%s()/%d Station nss[%d] mode[%d] mcs[%d] out of range, use default.\n"
             ,"_sta_caps_calculate",0x1ee,uVar6,uVar1,uVar2);
    }
    goto LAB_0048a98c;
  }
  if (iVar3 != 1) {
    if (iVar3 < 2) {
      if (iVar3 == 0) {
        *param_3 = 0;
        goto LAB_0048aa60;
      }
    }
    else {
      if (iVar3 == 3) {
        iVar3 = 2;
        goto LAB_0048aae8;
      }
      if (iVar3 == 5) {
        *param_3 = 3;
        param_3[4] = 0;
        return 0;
      }
    }
    if (wsta_roam_strategy_switch != '\0') {
      printf("[WSTA_ROAM_STRATEGY]%s()/%d Station nego_bw[%d] not recognized, judge it by freq_type[%d].\n"
             ,"_sta_caps_calculate",0x200,iVar3,param_2);
    }
    if (param_2 != 1) {
      *param_3 = 0;
LAB_0048aa60:
      param_3[4] = 0;
      return 0;
    }
    iVar3 = 2;
  }
LAB_0048aae8:
  *param_3 = (char)iVar3;
  param_3[4] = 0;
  return 0;
}

