// func ip_to_ac_data @ 00589cc8 size=224

uint ip_to_ac_data(uint param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  char *pcVar3;
  ushort in_stack_00000016;
  
  if (ac == 0) {
    uVar2 = 0xa5b;
    pcVar3 = "ac";
  }
  else {
    uVar1 = *(uint *)(ac + 0x18);
    if (uVar1 == 0) {
      uVar2 = 0xa5c;
      pcVar3 = "ac->ac_data_size > 0";
    }
    else {
      if ((param_1 >> 0x18) - 1 < 2) {
        if (param_1 >> 0x18 == 1) {
          param_2 = param_2 & 0xff;
        }
        if (uVar1 == 0) {
          trap(7);
        }
        if (uVar1 == 0) {
          trap(7);
        }
        return ((uint)in_stack_00000016 + param_2 % uVar1) % uVar1;
      }
      uVar2 = 0xa5d;
      pcVar3 = "UAC_IPADDR_TYPE_IPV4 == ip.ip_type || UAC_IPADDR_TYPE_IPV6 == ip.ip_type";
    }
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","ip_to_ac_data",uVar2,pcVar3);
  return 0xffffffff;
}

