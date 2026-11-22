// func _uac_dhcpv6def_packet_bind_svr_get @ 00460b30 size=88

undefined4 _uac_dhcpv6def_packet_bind_svr_get(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  byte bVar2;
  byte *pbVar3;
  
  bVar2 = *(byte *)(param_2 + 0x9b);
  uVar1 = 0xffffffff;
  if (bVar2 - 1 < 2) {
    if (bVar2 == 2) {
      bVar2 = 0;
    }
    pbVar3 = (byte *)(param_3 + param_1 * 0x11);
    *pbVar3 = bVar2;
    memcpy(pbVar3 + 1,(void *)(param_2 + 0x9c),0x10);
    uVar1 = 0;
  }
  return uVar1;
}

