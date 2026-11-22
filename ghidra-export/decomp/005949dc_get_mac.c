// func get_mac @ 005949dc size=60

undefined4 get_mac(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != 0) && (iVar1 = cw_sub_msg_ele_get(param_1,0x26,4), iVar1 != 0)) {
    uVar2 = *(undefined4 *)(iVar1 + 0x10);
  }
  return uVar2;
}

