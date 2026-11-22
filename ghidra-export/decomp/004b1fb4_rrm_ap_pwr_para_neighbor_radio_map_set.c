// func rrm_ap_pwr_para_neighbor_radio_map_set @ 004b1fb4 size=516

undefined4
rrm_ap_pwr_para_neighbor_radio_map_set(int param_1,uint param_2,uint param_3,char param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  
  param_3 = param_3 & 0xff;
  param_2 = param_2 & 0xffff;
  if ((param_1 == 0) || (*(int *)(param_1 + 0xc) <= (int)param_2)) {
    if (rrm_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[RRM_ERROR]%s()/%d wrong input\n","rrm_ap_pwr_para_neighbor_radio_map_set",0x191);
    return 0xffffffff;
  }
  FUN_004082d0(rrm_mutex,0xffffffff);
  iVar1 = (int)*(short *)(*(int *)(param_1 + 0x14) + param_2 * 2);
  if (iVar1 < 0) {
    if (rrm_err_switch == '\0') goto LAB_004b2158;
    pcVar4 = "[RRM_ERROR]%s()/%d ap[%d] is not calculated by rrm\n";
    uVar6 = 0x198;
    param_3 = param_2;
  }
  else {
    iVar2 = iVar1 * 0xf;
    iVar3 = *(int *)(param_1 + 0x1c) + iVar2;
    iVar5 = (int)*(char *)(iVar3 + param_3 + 2);
    iVar3 = iVar3 + iVar5;
    if (-1 < iVar5) {
      if (*(char *)(iVar3 + 0xc) != param_4) {
        *(char *)(iVar3 + 0xc) = param_4;
        iVar3 = *(int *)(param_1 + 0x1c) + iVar2;
        if (param_4 == '\0') {
          if (*(char *)(iVar3 + 0xb) != '\0') {
            *(char *)(iVar3 + 0xb) = *(char *)(iVar3 + 0xb) + -1;
            pcVar4 = (char *)(*(int *)(param_1 + 8) + iVar1);
            if (*pcVar4 != '\0') {
              *pcVar4 = '\0';
              *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
            }
          }
        }
        else {
          *(char *)(iVar3 + 0xb) = *(char *)(iVar3 + 0xb) + '\x01';
          if (*(char *)(*(int *)(param_1 + 0x1c) + iVar2 + 0xb) ==
              *(char *)(*(int *)(param_1 + 0x18) + iVar1 * 0x12 + 2)) {
            *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
            *(undefined1 *)(*(int *)(param_1 + 8) + iVar1) = 1;
          }
        }
      }
      FUN_00407f30(rrm_mutex);
      return 0;
    }
    if (rrm_err_switch == '\0') goto LAB_004b2158;
    pcVar4 = "[RRM_ERROR]%s()/%d radio_id[%d] is invalid\n";
    uVar6 = 0x1ba;
  }
  printf(pcVar4,"rrm_ap_pwr_para_neighbor_radio_map_set",uVar6,param_3);
LAB_004b2158:
  FUN_00407f30(rrm_mutex);
  return 0xffffffff;
}

