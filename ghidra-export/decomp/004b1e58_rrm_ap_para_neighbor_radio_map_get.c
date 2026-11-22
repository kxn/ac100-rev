// func rrm_ap_para_neighbor_radio_map_get @ 004b1e58 size=348

int rrm_ap_para_neighbor_radio_map_get(int param_1,uint param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  
  param_3 = param_3 & 0xff;
  param_2 = param_2 & 0xffff;
  if ((param_1 == 0) || (*(int *)(param_1 + 0xc) <= (int)param_2)) {
    if (rrm_err_switch == '\0') {
      return -1;
    }
    printf("[RRM_ERROR]%s()/%d wrong input\n","rrm_ap_para_neighbor_radio_map_get",0x170);
    return -1;
  }
  FUN_004082d0(rrm_mutex,0xffffffff);
  iVar2 = (int)*(short *)(*(int *)(param_1 + 0x14) + param_2 * 2);
  if (iVar2 < 0) {
    if (rrm_warning_switch == '\0') goto LAB_004b1f58;
    __format = "[RRM_WARNING]%s()/%d ap[%d] is not calculated by rrm\n";
    uVar4 = 0x177;
    param_3 = param_2;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x1c) + iVar2 * 0xf;
    iVar2 = (int)*(char *)(iVar3 + param_3 + 2);
    if (-1 < iVar2) {
      cVar1 = *(char *)(iVar3 + iVar2 + 0xc);
      FUN_00407f30(rrm_mutex);
      return (int)cVar1;
    }
    if (rrm_warning_switch == '\0') goto LAB_004b1f58;
    __format = "[RRM_WARNING]%s()/%d radio_id[%d] is invalid\n";
    uVar4 = 0x184;
  }
  printf(__format,"rrm_ap_para_neighbor_radio_map_get",uVar4,param_3);
LAB_004b1f58:
  FUN_00407f30(rrm_mutex);
  return -1;
}

