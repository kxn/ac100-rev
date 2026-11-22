// func _uac_mem_malloc @ 0051e2f8 size=1

int _uac_mem_malloc(int param_1)

{
  int iVar1;
  int iVar2;
  int in_t9;
  code *pcVar3;
  
  iVar1 = 0;
  if (((0 < param_1) &&
      (iVar1 = (**(code **)(in_t9 + 0x23b2e4))(), **(int **)(in_t9 + 0x23b158) != 0)) &&
     (iVar2 = *(int *)(in_t9 + 0x23b170), iVar1 != 0)) {
    (**(code **)(in_t9 + 0x23b5b4))(iVar2 + 0x3b38);
    pcVar3 = *(code **)(in_t9 + 0x23b4d4);
    **(int **)(in_t9 + 0x23b15c) = **(int **)(in_t9 + 0x23b15c) + 1;
    (*pcVar3)(iVar2 + 0x3b38);
  }
  return iVar1;
}

