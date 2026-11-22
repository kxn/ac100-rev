// func uci_lookup_option_string @ 0064be40 size=76

undefined4 uci_lookup_option_string(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_10 [3];
  
  local_10[0] = 0;
  iVar1 = uci_lookup_next(param_1,local_10,param_2 + 0x10,param_3);
  uVar2 = 0;
  if (((iVar1 == 0) && (local_10[0] != 0)) && (*(int *)(local_10[0] + 0x14) == 0)) {
    uVar2 = *(undefined4 *)(local_10[0] + 0x18);
  }
  return uVar2;
}

