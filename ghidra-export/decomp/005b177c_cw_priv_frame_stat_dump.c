// func cw_priv_frame_stat_dump @ 005b177c size=636

undefined4 cw_priv_frame_stat_dump(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private frame state \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private frame state (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x... \r\n",(uint)*pbVar1);
  printf("\t\t\t\tradio id: %d \r\n",(uint)*pbVar1);
  printf("\t\t\t\treserved: %02x%02x%02x \r\n",(uint)pbVar1[1],(uint)pbVar1[2],(uint)pbVar1[3]);
  printf("\t\t\t\trx assoc badwpaie: %d \r\n",*(undefined4 *)(pbVar1 + 4));
  printf("\t\t\t\trx assoc capmismatch: %d \r\n",*(undefined4 *)(pbVar1 + 8));
  printf("\t\t\t\trx assoc norate: %d \r\n",*(undefined4 *)(pbVar1 + 0xc));
  printf("\t\t\t\trx assoc notauth: %d \r\n",*(undefined4 *)(pbVar1 + 0x10));
  printf("\t\t\t\trx assoc ok: %d \r\n",*(undefined4 *)(pbVar1 + 0x14));
  printf("\t\t\t\trx assoc wrongbss: %d \r\n",*(undefined4 *)(pbVar1 + 0x18));
  printf("\t\t\t\trx assoc pkt: %d \r\n",*(undefined4 *)(pbVar1 + 0x1c));
  printf("\t\t\t\trx auth bad: %d \r\n",*(undefined4 *)(pbVar1 + 0x20));
  printf("\t\t\t\trx auth fail: %d \r\n",*(undefined4 *)(pbVar1 + 0x24));
  printf("\t\t\t\trx auth ok: %d \r\n",*(undefined4 *)(pbVar1 + 0x28));
  printf("\t\t\t\trx auth pkt: %d \r\n",*(undefined4 *)(pbVar1 + 0x2c));
  printf("\t\t\t\trx auth unspport: %d \r\n",*(undefined4 *)(pbVar1 + 0x30));
  printf("\t\t\t\trx deauth pkt: %d \r\n",*(undefined4 *)(pbVar1 + 0x34));
  printf("\t\t\t\trx disassoc pkt: %d \r\n",*(undefined4 *)(pbVar1 + 0x38));
  printf("\t\t\t\trx reassoc ok: %d \r\n",*(undefined4 *)(pbVar1 + 0x3c));
  printf("\t\t\t\trx reassoc pkt: %d \r\n",*(undefined4 *)(pbVar1 + 0x40));
  printf("\t\t\t\trx crc err: %d \r\n",*(undefined4 *)(pbVar1 + 0x44));
  printf("\t\t\t\trx decryp err: %d \r\n",*(undefined4 *)(pbVar1 + 0x48));
  printf("\t\t\t\trx data tot pkt: %d \r\n",*(undefined4 *)(pbVar1 + 0x4c));
  printf("\t\t\t\trx data tot byte: %d \r\n",*(undefined4 *)(pbVar1 + 0x50));
  printf("\t\t\t\trx tot pkt: %d \r\n",*(undefined4 *)(pbVar1 + 0x54));
  printf("\t\t\t\trx tot byte: %d \r\n",*(undefined4 *)(pbVar1 + 0x58));
  printf("\t\t\t\ttx deauth pkt: %d \r\n",*(undefined4 *)(pbVar1 + 0x5c));
  printf("\t\t\t\ttx disassoc pkt: %d \r\n",*(undefined4 *)(pbVar1 + 0x60));
  printf("\t\t\t\ttx rts ok: %d \r\n",*(undefined4 *)(pbVar1 + 100));
  printf("\t\t\t\ttx rts fail: %d \r\n",*(undefined4 *)(pbVar1 + 0x68));
  printf("\t\t\t\ttx data tot pkt: %d \r\n",*(undefined4 *)(pbVar1 + 0x6c));
  printf("\t\t\t\ttx data tot byte: %d \r\n",*(undefined4 *)(pbVar1 + 0x70));
  printf("\t\t\t\ttx tot pkt: %d \r\n",*(undefined4 *)(pbVar1 + 0x74));
  printf("\t\t\t\ttx tot byte: %d \r\n",*(undefined4 *)(pbVar1 + 0x78));
  return 0;
}

