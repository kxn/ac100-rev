// func rrm_global_config_dump @ 004ae60c size=1044

void rrm_global_config_dump(void)

{
  byte bVar1;
  undefined4 uVar2;
  undefined *puVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  
  puVar5 = &DAT_00731928;
  puts("******global config info*********");
  printf("ac mac:\t%02x%02x%02x%02x%02x%02x\n",(uint)ctl,(uint)DAT_00731905,(uint)DAT_00731906,
         (uint)DAT_00731907,(uint)DAT_00731908,(uint)DAT_00731909);
  puts("group_id:\t");
  uVar2 = DAT_00731928;
  while( true ) {
    puVar5 = puVar5 + 1;
    printf("%d-",uVar2);
    if (puVar5 == &DAT_00731964) break;
    uVar2 = *puVar5;
  }
  printf("%d\n",DAT_00731964);
  if (DAT_00731920 == 0) {
    pcVar4 = "Led off";
  }
  else {
    pcVar4 = "Led on";
  }
  printf("freq_24g_enable:\t%s\n",pcVar4 + 4);
  if (DAT_00731924 == 0) {
    pcVar4 = "Led off";
  }
  else {
    pcVar4 = "Led on";
  }
  printf("freq_5g_enable:\t%s\n",pcVar4 + 4);
  printf("rssi_threshold:\t%d\n",(int)DAT_0073190a);
  printf("period:\t%d\n",(uint)DAT_0073190c);
  printf("duration:\t%d\n",(uint)DAT_0073190e);
  printf("max_neigh:\t%d\n",(uint)DAT_00731910);
  printf("expired:\t%d\n\n",(uint)DAT_00731912);
  if (g_pwr_enable == 0) {
    pcVar4 = "Led off";
  }
  else {
    pcVar4 = "Led on";
  }
  printf("g_pwr_enable:\t%s\n",pcVar4 + 4);
  printf("high_threshold:\t%d\n",(int)high_threshold);
  printf("low_threshold:\t%d\n",(int)low_threshold);
  printf("rrm_pwr_max_power:\t%d\n",rrm_pwr_max_power);
  printf("rrm_pwr_min_power:\t%d\n\n",rrm_pwr_min_power);
  if (g_chnl_enable == 0) {
    pcVar4 = "Led off";
  }
  else {
    pcVar4 = "Led on";
  }
  printf("g_chnl_enable:\t%s\n",pcVar4 + 4);
  if (g_bw_2g == 0) {
    puVar3 = &DAT_006a0630;
  }
  else {
    puVar3 = &DAT_006a0634;
  }
  printf("g_bw_2g:\t%s\n",puVar3);
  if (g_bw_5g == 0) {
    pcVar4 = "20M";
  }
  else if (g_bw_5g == 1) {
    pcVar4 = "40M";
  }
  else if (g_bw_5g == 3) {
    pcVar4 = "80M";
  }
  else {
    pcVar4 = "160M";
  }
  printf("g_bw_5g:\t%s\n",pcVar4);
  puts("rrm channel list:");
  pbVar7 = &rrm_channel_list;
  iVar8 = 0;
  puVar3 = &DAT_00693fd4;
  iVar6 = 1;
  while( true ) {
    printf("\tradio id:%s%d\tchannel list:",puVar3,iVar6);
    bVar1 = *pbVar7;
    for (iVar6 = 0; iVar6 < (int)(uint)bVar1; iVar6 = iVar6 + 1) {
      if (iVar6 == 0) {
        bVar1 = pbVar7[1];
        pcVar4 = "%d";
      }
      else {
        bVar1 = pbVar7[iVar6 + 1];
        pcVar4 = ",%d";
      }
      printf(pcVar4,(uint)bVar1);
      bVar1 = *pbVar7;
    }
    iVar8 = iVar8 + 1;
    putchar(10);
    pbVar7 = pbVar7 + 5;
    if (iVar8 == 3) break;
    if (iVar8 == 0) {
      puVar3 = &DAT_00693fd4;
      iVar6 = 1;
    }
    else {
      puVar3 = &DAT_00693fd0;
      iVar6 = iVar8;
    }
  }
  if (g_autorrm_enable == 0) {
    pcVar4 = "Led off";
  }
  else {
    pcVar4 = "Led on";
  }
  printf("\ng_autorrm_enable:\t%s\n",pcVar4 + 4);
  if (g_autorrm_date < 8) {
    pcVar4 = (&PTR_DAT_006a14c4)[g_autorrm_date];
  }
  else {
    pcVar4 = "unknown";
  }
  printf("\ng_autorrm_date:\t\t%s\n",pcVar4);
  printf("\ng_autorrm_time:\t\t%02d:%02d:%02d\n",g_autorrm_time,DAT_00767bc4,DAT_00767bc8);
  puts("********************************");
  return;
}

