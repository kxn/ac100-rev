// func _roaming_nbr_select @ 004871bc size=1108

void _roaming_nbr_select(undefined4 param_1,int param_2,int *param_3,int param_4,int *param_5,
                        int param_6,byte param_7)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined4 local_1b8;
  undefined1 local_1b4;
  uint local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  int local_1a4;
  char local_1a0 [12];
  int local_194 [12];
  int local_164 [12];
  char acStack_134 [260];
  int local_30;
  
  memset(acStack_134,0,0x100);
  memset(&local_1b8,0,0x24);
  uVar8 = (uint)param_7;
  if ((uint)wsta_roam_max_nbr < (uint)param_7) {
    uVar8 = (uint)wsta_roam_max_nbr;
  }
  *param_3 = 0;
  *param_5 = 0;
  local_1b4 = *(undefined1 *)(param_2 + 0x17);
  local_1ac = *(undefined4 *)(param_2 + 0x18);
  local_1b0 = (uint)*(byte *)(param_2 + 0x15);
  iVar4 = 0;
  local_1b8 = param_1;
  if (((*(byte *)(param_2 + 0x15) & 6) != 0) && (cVar1 = *(char *)(param_2 + 0x1d), cVar1 != '\0'))
  {
    local_1a8 = 1;
    local_1a4 = param_2 + 0x140;
    memcpy(local_194,&l_roaming_nbr_index_array,0x30);
    FUN_00486664(local_194,&local_1b8,cVar1);
    if (wsta_roam_strategy_switch != '\0') {
      piVar7 = local_194;
      memset(acStack_134,0,0x100);
      while (iVar4 < (int)(uint)*(byte *)(param_2 + 0x1d)) {
        if (iVar4 == 0) {
          sprintf(acStack_134,"%d",*piVar7);
          iVar4 = 1;
          piVar7 = piVar7 + 1;
        }
        else {
          sprintf(acStack_134,"%s,%d",acStack_134);
          iVar4 = iVar4 + 1;
          piVar7 = piVar7 + 1;
        }
      }
      if (wsta_roam_strategy_switch != '\0') {
        printf("[WSTA_ROAM_STRATEGY]%s()/%d 5g nbr sort result:[%s]\n","_roaming_nbr_select",0x298,
               acStack_134);
      }
    }
    piVar7 = local_194;
    iVar6 = 0;
    local_30 = param_2 + 0xc;
    iVar4 = 0;
    while( true ) {
      if ((int)(uint)*(byte *)(param_2 + 0x1d) <= iVar6) break;
      if ((int)uVar8 <= iVar4) {
        bVar2 = *(byte *)(param_2 + 0x15);
        goto LAB_00487280;
      }
      iVar5 = *piVar7;
      if (((int)(uint)*(byte *)(param_2 + 0x1d) <= iVar5) || (local_1a0[iVar5] != '\0')) break;
      iVar3 = param_2 + iVar5 * 0x18 + 0x140;
      iVar3 = uac_wsta_pseudo_associate_check
                        (*(undefined2 *)(iVar3 + 6),*(undefined1 *)(iVar3 + 8),
                         *(undefined1 *)(iVar3 + 0xd),local_30);
      iVar6 = iVar6 + 1;
      if (iVar3 == 0) {
        iVar4 = iVar4 + 1;
        *(int *)(param_6 + *param_5 * 4) = iVar5;
        *param_5 = *param_5 + 1;
      }
      piVar7 = piVar7 + 1;
    }
  }
  bVar2 = *(byte *)(param_2 + 0x15);
LAB_00487280:
  if ((bVar2 & 1) == 0) {
    if ((bVar2 & 6) == 0) {
      return;
    }
    cVar1 = *(char *)(param_2 + 0x1c);
  }
  else {
    cVar1 = *(char *)(param_2 + 0x1c);
  }
  if ((cVar1 != '\0') && (iVar4 < (int)uVar8)) {
    local_1a8 = 0;
    local_1a4 = param_2 + 0x20;
    local_1a0[0] = '\0';
    local_1a0[1] = '\0';
    local_1a0[2] = '\0';
    local_1a0[3] = '\0';
    local_1a0[4] = '\0';
    local_1a0[5] = '\0';
    local_1a0[6] = '\0';
    local_1a0[7] = '\0';
    local_1a0[8] = '\0';
    local_1a0[9] = '\0';
    local_1a0[10] = '\0';
    local_1a0[0xb] = '\0';
    memcpy(local_164,&l_roaming_nbr_index_array,0x30);
    FUN_00486664(local_164,&local_1b8,cVar1);
    if (wsta_roam_strategy_switch != '\0') {
      piVar7 = local_164;
      iVar6 = 0;
      memset(acStack_134,0,0x100);
      while (iVar6 < (int)(uint)*(byte *)(param_2 + 0x1c)) {
        if (iVar6 == 0) {
          iVar6 = 1;
          sprintf(acStack_134,"%d",*piVar7);
          piVar7 = piVar7 + 1;
        }
        else {
          sprintf(acStack_134,"%s,%d",acStack_134);
          iVar6 = iVar6 + 1;
          piVar7 = piVar7 + 1;
        }
      }
      if (wsta_roam_strategy_switch != '\0') {
        printf("[WSTA_ROAM_STRATEGY]%s()/%d 2g nbr sort result:[%s]\n","_roaming_nbr_select",0x2cd,
               acStack_134);
      }
    }
    piVar7 = local_164;
    iVar6 = 0;
    while( true ) {
      if (((((int)(uint)*(byte *)(param_2 + 0x1c) <= iVar6) || ((int)uVar8 <= iVar4)) ||
          (iVar5 = *piVar7, (int)(uint)*(byte *)(param_2 + 0x1c) <= iVar5)) ||
         (local_1a0[iVar5] != '\0')) break;
      iVar3 = param_2 + iVar5 * 0x18 + 0x20;
      iVar3 = uac_wsta_pseudo_associate_check
                        (*(undefined2 *)(iVar3 + 6),*(undefined1 *)(iVar3 + 8),
                         *(undefined1 *)(iVar3 + 0xd),param_2 + 0xc);
      if (iVar3 == 0) {
        iVar4 = iVar4 + 1;
        iVar6 = iVar6 + 1;
        piVar7 = piVar7 + 1;
        *(int *)(param_4 + *param_3 * 4) = iVar5;
        *param_3 = *param_3 + 1;
      }
      else if (wsta_roam_strategy_switch == '\0') {
        iVar6 = iVar6 + 1;
        piVar7 = piVar7 + 1;
      }
      else {
        printf("[WSTA_ROAM_STRATEGY]%s()/%d uac_wsta_test_associate() reject\n",
               "_roaming_nbr_select",0x2dc);
        iVar6 = iVar6 + 1;
        piVar7 = piVar7 + 1;
      }
    }
  }
  return;
}

