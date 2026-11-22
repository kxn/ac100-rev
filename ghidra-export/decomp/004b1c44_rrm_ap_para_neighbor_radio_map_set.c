// func rrm_ap_para_neighbor_radio_map_set @ 004b1c44 size=532

undefined4 rrm_ap_para_neighbor_radio_map_set(int param_1,uint param_2,uint param_3,char param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  
  param_3 = param_3 & 0xff;
  param_2 = param_2 & 0xffff;
  if ((param_1 == 0) || (*(int *)(param_1 + 0xc) <= (int)param_2)) {
    if (rrm_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[RRM_ERROR]%s()/%d wrong input\n","rrm_ap_para_neighbor_radio_map_set",0x13a);
    return 0xffffffff;
  }
  FUN_004082d0(rrm_mutex,0xffffffff);
  iVar2 = (int)*(short *)(*(int *)(param_1 + 0x14) + param_2 * 2);
  if (iVar2 < 0) {
    if (rrm_err_switch == '\0') goto LAB_004b1df8;
    pcVar5 = "[RRM_ERROR]%s()/%d ap[%d] is not calculated by rrm\n";
    uVar7 = 0x141;
    param_3 = param_2;
  }
  else {
    iVar3 = iVar2 * 0xf;
    iVar4 = *(int *)(param_1 + 0x1c) + iVar3;
    iVar6 = (int)*(char *)(iVar4 + param_3 + 2);
    iVar4 = iVar4 + iVar6;
    if (-1 < iVar6) {
      if (*(char *)(iVar4 + 0xc) != param_4) {
        *(char *)(iVar4 + 0xc) = param_4;
        iVar4 = *(int *)(param_1 + 0x1c) + iVar3;
        cVar1 = *(char *)(iVar4 + 0xb);
        if (param_4 == '\0') {
          if (cVar1 != '\0') {
            *(char *)(iVar4 + 0xb) = cVar1 + -1;
            pcVar5 = (char *)(*(int *)(param_1 + 8) + iVar2);
            if ((*pcVar5 != '\0') && (*(char *)(*(int *)(param_1 + 0x1c) + iVar3 + 0xb) == '\0')) {
              *pcVar5 = '\0';
              *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
            }
          }
        }
        else {
          *(char *)(iVar4 + 0xb) = cVar1 + '\x01';
          if (*(char *)(*(int *)(param_1 + 0x1c) + iVar3 + 0xb) ==
              *(char *)(*(int *)(param_1 + 0x18) + iVar2 * 0x2a + 2)) {
            *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
            *(undefined1 *)(*(int *)(param_1 + 8) + iVar2) = 1;
          }
        }
      }
      FUN_00407f30(rrm_mutex);
      return 0;
    }
    if (rrm_err_switch == '\0') goto LAB_004b1df8;
    pcVar5 = "[RRM_ERROR]%s()/%d radio_id[%d] is invalid\n";
    uVar7 = 0x163;
  }
  printf(pcVar5,"rrm_ap_para_neighbor_radio_map_set",uVar7,param_3);
LAB_004b1df8:
  FUN_00407f30(rrm_mutex);
  return 0xffffffff;
}

