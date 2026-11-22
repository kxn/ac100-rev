// func FUN_0066a080 @ 0066a080 size=1404

void FUN_0066a080(ushort *param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  char cVar4;
  byte bVar5;
  bool bVar6;
  int iVar7;
  uint extraout_v1;
  char *pcVar8;
  char *pcVar9;
  ushort *puVar10;
  uint uVar11;
  int iVar12;
  
  FUN_00407e70();
  if (param_1 != (ushort *)0x0) {
    uVar11 = (uint)*(byte *)((int)param_1 + 0x55);
    printf("id: %d\r\n",(uint)*param_1);
    if ((param_1[6] & 0x100) == 0) {
      pcVar8 = "inactive";
    }
    else {
      pcVar8 = "active";
    }
    if ((param_1[6] & 0x200) == 0) {
      pcVar9 = "not-ready";
    }
    else {
      pcVar9 = "ready";
    }
    printf("state: %s, %s\r\n",pcVar8,pcVar9);
    iVar12 = 0;
    printf("mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*(byte *)(param_1 + 1),
           (uint)*(byte *)((int)param_1 + 3),(uint)*(byte *)(param_1 + 2),
           (uint)*(byte *)((int)param_1 + 5),(uint)*(byte *)(param_1 + 3),
           (uint)*(byte *)((int)param_1 + 7));
    printf("\tap id: %u \r\n",(uint)param_1[4]);
    printf("\tradio id: %u \r\n",(uint)*(byte *)(param_1 + 5));
    printf("\twlan id: %u \r\n",(uint)*(byte *)((int)param_1 + 0xb));
    printf("\tauth type: %u \r\n",(uint)*(byte *)((int)param_1 + 0xd));
    printf("\tenc alg: %u \r\n",(uint)*(byte *)(param_1 + 7));
    printf("\trssi: %d dBm\r\n",(int)*(char *)((int)param_1 + 0xf));
    printf("\tnego bw: %d \r\n",(int)*(char *)(param_1 + 8));
    printf("\tnego bw max 2g: %d \r\n",(int)*(char *)((int)param_1 + 0x11));
    printf("\tnego bw max 5g: %d \r\n",(int)*(char *)(param_1 + 9));
    printf("\tnego bw: %d \r\n",(int)*(char *)(param_1 + 8));
    printf("\tnego rate: %u Mbps\r\n",(uint)param_1[10]);
    printf("\tsupport_2g: 0x%08x \r\n",*(undefined4 *)(param_1 + 0xc));
    printf("\tsupport_5g: 0x%08x \r\n",*(undefined4 *)(param_1 + 0xe));
    printf("\tcapabilities: 0x%04x \r\n",(uint)param_1[0x10]);
    printf("\tpacket rtx rate: %u%% \r\n",(uint)*(byte *)(param_1 + 0x11));
    printf("\tpacket loss rate: %u%% \r\n",(uint)*(byte *)((int)param_1 + 0x23));
    printf("\tupstream rate: %u Kbps\r\n",*(undefined4 *)(param_1 + 0x12));
    printf("\tdownstream rate: %u Kbps\r\n",*(undefined4 *)(param_1 + 0x14));
    printf("\tupstream load: %llu KBytes\r\n");
    printf("\tdownstream load: %llu KBytes\r\n");
    iVar7 = *(uint *)(param_1 + 0x20) - extraout_v1;
    if (*(uint *)(param_1 + 0x20) <= extraout_v1) {
      iVar7 = 0;
    }
    printf("\ttime to expire: %u \r\n",iVar7);
    printf("\tac_report_last_time: %llu \r\n");
    puts("\t***************sample area start***************\r");
    printf("\tsample_dense_count: %u\r\n",(uint)*(byte *)(param_1 + 0x2a));
    printf("\tsample_normal_count: %u\r\n",(uint)*(byte *)((int)param_1 + 0x55));
    printf("\tsample_normal_last_time: %llu\r\n");
    printf("\tsample_up_load_cumulate: %u KBytes\r\n",*(undefined4 *)(param_1 + 0x30));
    printf("\tsample_down_load_cumulate: %u KBytes\r\n",*(undefined4 *)(param_1 + 0x32));
    printf("\tsample_up_rate: ");
    bVar6 = uVar11 != 0;
    puVar10 = param_1;
    while (bVar6) {
      iVar12 = iVar12 + 1;
      printf("%u ",*(undefined4 *)(puVar10 + 0x34));
      bVar6 = iVar12 < (int)uVar11;
      puVar10 = puVar10 + 2;
    }
    puts(" KBps\r");
    printf("\tsample_down_rate: ");
    puVar10 = param_1;
    for (iVar7 = 0; iVar7 < (int)uVar11; iVar7 = iVar7 + 1) {
      printf("%u ",*(undefined4 *)(puVar10 + 0x48));
      puVar10 = puVar10 + 2;
    }
    puts(" KBps\r");
    printf("\tsample_upstream_load: ");
    puVar10 = param_1;
    for (iVar7 = 0; iVar7 < (int)uVar11; iVar7 = iVar7 + 1) {
      printf("%u ",*(undefined4 *)(puVar10 + 0x5c));
      puVar10 = puVar10 + 2;
    }
    puts(" KBytes\r");
    iVar7 = 0;
    printf("\tsample_downstream_load: ");
    bVar6 = uVar11 != 0;
    puVar10 = param_1;
    while (bVar6) {
      iVar7 = iVar7 + 1;
      printf("%u ",*(undefined4 *)(puVar10 + 0x70));
      bVar6 = iVar7 < (int)uVar11;
      puVar10 = puVar10 + 2;
    }
    puts(" KBytes\r");
    printf("\tsample_rssi: ");
    bVar6 = uVar11 != 0;
    iVar7 = 0;
    while (bVar6) {
      printf("%u ",(int)*(char *)((int)param_1 + iVar7 + 0x108));
      bVar6 = iVar7 + 1 < (int)uVar11;
      iVar7 = iVar7 + 1;
    }
    puts(" \r");
    iVar7 = 0;
    printf("\tsample_nego_rate: ");
    bVar6 = uVar11 != 0;
    puVar10 = param_1;
    while (bVar6) {
      iVar7 = iVar7 + 1;
      printf("%u ",(uint)puVar10[0x89]);
      bVar6 = iVar7 < (int)uVar11;
      puVar10 = puVar10 + 1;
    }
    puts(" KBytes\r");
    puts("\t***************sample area done ***************\r");
    puts("\t***************nbr area ******************\r");
    printf("\tnbr count: %u\r\n",(uint)*(byte *)(param_1 + 0xdc));
    if ((*(byte *)((int)param_1 + 0x1b9) & 1) == 0) {
      pcVar8 = "inactive";
    }
    else {
      pcVar8 = "active";
    }
    if ((*(byte *)((int)param_1 + 0x1b9) & 2) == 0) {
      pcVar9 = "not-ready";
    }
    else {
      pcVar9 = "ready";
    }
    printf("\tstate: %s, %s\r\n",pcVar8,pcVar9);
    puVar10 = param_1;
    for (iVar7 = 0; iVar7 < (int)(uint)*(byte *)(param_1 + 0xdc); iVar7 = iVar7 + 1) {
      puVar1 = puVar10 + 0x94;
      puVar2 = puVar10 + 0x96;
      puVar3 = puVar10 + 0x97;
      if (extraout_v1 - *(int *)puVar1 < stats_nbr_expire_time) {
        bVar5 = *(byte *)((int)puVar10 + 0x12f);
        cVar4 = *(char *)(puVar10 + 0x98);
        pcVar8 = 
        "\t\tidx=%d[active], ap id: %u, radio id: %u, wlan id: %u, rssi: %d, elapse: %u seconds\r\n"
        ;
      }
      else {
        bVar5 = *(byte *)((int)puVar10 + 0x12f);
        pcVar8 = 
        "\t\tidx=%d[expired], ap id: %u, radio id: %u, wlan id: %u, rssi: %d, elapse: %u seconds\r\n"
        ;
        cVar4 = *(char *)(puVar10 + 0x98);
      }
      puVar10 = puVar10 + 6;
      printf(pcVar8,iVar7,(uint)*puVar2,(uint)*(byte *)puVar3,(uint)bVar5,(int)cVar4,
             extraout_v1 - *(int *)puVar1);
    }
  }
  return;
}

