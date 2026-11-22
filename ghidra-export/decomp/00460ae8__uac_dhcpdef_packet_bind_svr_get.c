// func _uac_dhcpdef_packet_bind_svr_get @ 00460ae8 size=72

undefined4 _uac_dhcpdef_packet_bind_svr_get(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  byte *pbVar2;
  
  uVar1 = 0xffffffff;
  if (*(byte *)(param_2 + 0x9b) < 2) {
    pbVar2 = (byte *)(param_3 + param_1 * 7);
    *pbVar2 = *(byte *)(param_2 + 0x9b);
    memcpy(pbVar2 + 1,(void *)(param_2 + 0x9c),6);
    uVar1 = 0;
  }
  return uVar1;
}

