// func _cmcc_wq_compare_func @ 0042bc88 size=180

int _cmcc_wq_compare_func(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_18;
  undefined2 local_14;
  
  local_18 = 0;
  local_14 = 0;
  iVar1 = memcmp((void *)(param_2 + 0x28),&local_18,6);
  if ((((iVar1 == 0) && (iVar1 = memcmp((void *)(param_1 + 0x28),&local_18,6), iVar1 == 0)) &&
      (*(int *)(param_2 + 0x20) != 0)) && (*(int *)(param_1 + 0x20) != 0)) {
    iVar1 = -1;
    if (*(int *)(param_2 + 0x20) == *(int *)(param_1 + 0x20)) {
      iVar1 = 0;
    }
    return iVar1;
  }
  iVar1 = memcmp((void *)(param_1 + 0x28),(void *)(param_2 + 0x28),6);
  return iVar1;
}

