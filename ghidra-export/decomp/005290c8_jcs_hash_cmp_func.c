// func jcs_hash_cmp_func @ 005290c8 size=128

bool jcs_hash_cmp_func(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int in_t9;
  
  if (param_1 == 0) {
    piVar1 = *(int **)(in_t9 + 0x230128);
  }
  else {
    piVar1 = *(int **)(in_t9 + 0x230128);
    if (param_2 != 0) {
      iVar2 = (**(code **)(in_t9 + 0x23050c))();
      return iVar2 == 0;
    }
  }
  if (*piVar1 != 0) {
    (**(code **)(in_t9 + 0x230808))
              (*(int *)(in_t9 + 0x230060) + 0x5004,*(int *)(in_t9 + 0x230060) + 0x5394,0x9d,param_4,
               in_t9 + 0x238038);
  }
  return false;
}

