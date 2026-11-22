// func cw_msg_ele_priv_val_get @ 00582c9c size=44

undefined4 cw_msg_ele_priv_val_get(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = cw_msg_ele_priv_get(param_1,param_2);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x10);
  }
  return uVar2;
}

