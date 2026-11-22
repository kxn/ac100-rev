// func cw_ac_data_size_get @ 00589c7c size=76

undefined4 cw_ac_data_size_get(void)

{
  undefined4 uVar1;
  
  if (ac == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_data_size_get",0xa4c,"ac");
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(ac + 0x18);
  }
  return uVar1;
}

