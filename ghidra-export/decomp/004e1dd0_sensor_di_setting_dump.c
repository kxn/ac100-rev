// func sensor_di_setting_dump @ 004e1dd0 size=332

void sensor_di_setting_dump(void)

{
  int iVar1;
  int iVar2;
  
  FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
  puts("=====show di setting========");
  if ((l_sensor_di_setting != 0) && (-1 < l_sensor_di_setting_cnt)) {
    printf("there are %d settings\n");
    for (iVar1 = 0; iVar2 = iVar1 * 0xa4, iVar1 < l_sensor_di_setting_cnt; iVar1 = iVar1 + 1) {
      printf("setting No.%d:\n",iVar1);
      printf("    sensor_id=%d\n",*(undefined4 *)(l_sensor_di_setting + iVar2));
      printf("    inspection_item=%d\n",(uint)*(byte *)(l_sensor_di_setting + iVar2 + 4));
      printf("    inspection_band=%d\n",(uint)*(byte *)(l_sensor_di_setting + iVar2 + 5));
    }
  }
  puts("============================");
  puts("PS:");
  puts("inspection_item EXPLAIN: bit0=pkt stat, bit1=freq analysis, bit2=chnls scan");
  FUN_00407f30(l_sensor_di_data_mutex);
  return;
}

