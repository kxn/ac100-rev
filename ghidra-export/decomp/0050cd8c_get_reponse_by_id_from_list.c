// func get_reponse_by_id_from_list @ 0050cd8c size=84

int get_reponse_by_id_from_list(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if ((param_1 != 0) && (iVar1 = FUN_004081b0(param_1 + 4), iVar1 != 0)) {
    iVar2 = *(int *)(iVar1 + 0xc);
    while ((param_2 != iVar2 && (iVar1 = FUN_00408680(iVar1), iVar1 != 0))) {
      iVar2 = *(int *)(iVar1 + 0xc);
    }
  }
  return iVar1;
}

