// func get_apdb_flag_bit @ 00601c58 size=108

int get_apdb_flag_bit(char *param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  ppuVar2 = &PTR_s_0_00701cb4;
  iVar3 = 0;
  do {
    iVar1 = strcmp(param_1,*ppuVar2);
    if (iVar1 == 0) {
      return iVar3;
    }
    iVar3 = iVar3 + 1;
    ppuVar2 = ppuVar2 + 1;
  } while (iVar3 != 6);
  return 6;
}

