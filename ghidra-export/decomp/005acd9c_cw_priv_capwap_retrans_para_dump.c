// func cw_priv_capwap_retrans_para_dump @ 005acd9c size=196

undefined4 cw_priv_capwap_retrans_para_dump(int param_1)

{
  undefined *puVar1;
  byte *pbVar2;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private capwap retransmit parameter \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private capwap retransmit parameter (%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%04x%02x \r\n",(uint)*pbVar2,(uint)*(ushort *)(pbVar2 + 2),
         (uint)pbVar2[4]);
  printf("\t\t\t\ttimes: %d \r\n",(uint)*pbVar2);
  printf("\t\t\t\tinterval: %d \r\n",(uint)*(ushort *)(pbVar2 + 2));
  if (pbVar2[4] == 0) {
    puVar1 = &DAT_00691368;
  }
  else {
    puVar1 = &DAT_006a2b04;
  }
  printf("\t\t\t\tfixed: %s \r\n",puVar1);
  return 0;
}

