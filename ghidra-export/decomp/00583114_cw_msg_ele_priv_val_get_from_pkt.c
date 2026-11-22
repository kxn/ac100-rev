// func cw_msg_ele_priv_val_get_from_pkt @ 00583114 size=60

undefined4 cw_msg_ele_priv_val_get_from_pkt(int param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != 0) && (iVar1 = cw_msg_ele_priv_get_from_pkt(param_1,param_2), iVar1 != 0)) {
    uVar2 = *(undefined4 *)(iVar1 + 0x10);
  }
  return uVar2;
}

