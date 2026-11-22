// func _opensocket @ 004b5b68 size=52

void _opensocket(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = socket(*param_3,param_3[1],param_3[2]);
  *param_1 = iVar1;
  return;
}

