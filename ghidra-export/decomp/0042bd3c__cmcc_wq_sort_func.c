// func _cmcc_wq_sort_func @ 0042bd3c size=164

uint _cmcc_wq_sort_func(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 local_18;
  undefined2 local_14;
  
  local_18 = 0;
  local_14 = 0;
  iVar1 = memcmp((void *)(param_1 + 0x28),&local_18,6);
  if ((((iVar1 == 0) && (iVar1 = memcmp((void *)(param_2 + 0x28),&local_18,6), iVar1 == 0)) &&
      (*(uint *)(param_1 + 0x20) != 0)) && (*(uint *)(param_2 + 0x20) != 0)) {
    return (uint)(*(uint *)(param_2 + 0x20) < *(uint *)(param_1 + 0x20));
  }
  uVar2 = memcmp((void *)(param_1 + 0x28),(void *)(param_2 + 0x28),6);
  return uVar2;
}

