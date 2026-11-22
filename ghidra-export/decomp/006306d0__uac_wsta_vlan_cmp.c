// func _uac_wsta_vlan_cmp @ 006306d0 size=56

bool _uac_wsta_vlan_cmp(int param_1,char *param_2)

{
  uint uVar1;
  
  uVar1 = atoi(param_2);
  return (uint)*(ushort *)(param_1 + 0x2e) != (uVar1 & 0xffff);
}

