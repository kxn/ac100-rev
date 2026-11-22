// func jcs_hash_obj_func @ 005291e0 size=1

undefined4 jcs_hash_obj_func(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int in_t9;
  int iVar2;
  
  if (param_1 == 0) {
    if (**(int **)(in_t9 + 0x230010) != 0) {
      (**(code **)(in_t9 + 0x2306f0))
                (*(int *)(in_t9 + 0x22ff48) + 0x5004,*(int *)(in_t9 + 0x22ff48) + 0x53bc,0x88,
                 param_4,in_t9 + 0x237f20);
    }
    return 0;
  }
  iVar2 = *(int *)(in_t9 + 0x230330);
  if (param_1 == 0) {
    if (**(int **)(iVar2 + 0x2291f0) != 0) {
      (**(code **)(iVar2 + 0x2298d0))
                (*(int *)(iVar2 + 0x229128) + 0x5004,*(int *)(iVar2 + 0x229128) + 0x53a8,0x6f,
                 param_4,iVar2 + 0x231100);
    }
    return 0;
  }
  uVar1 = (**(code **)(iVar2 + 0x22961c))();
  uVar1 = uac_hash_update(param_1,uVar1,0);
  return uVar1;
}

