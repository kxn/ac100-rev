// func _uac_wsta_mac_cmp @ 0063079c size=140

bool _uac_wsta_mac_cmp(int param_1,char *param_2)

{
  char *pcVar1;
  char acStack_110 [260];
  
  memset(acStack_110,0,0x100);
  snprintf(acStack_110,0x100,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x68),
           (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),
           (uint)*(byte *)(param_1 + 0x6b),(uint)*(byte *)(param_1 + 0x6c),
           (uint)*(byte *)(param_1 + 0x6d));
  pcVar1 = strstr(acStack_110,param_2);
  return pcVar1 == (char *)0x0;
}

