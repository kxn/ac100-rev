// func _sensor_di_collect_pkt_stat_data_parse_pktdata @ 004d4d40 size=1520

undefined4
_sensor_di_collect_pkt_stat_data_parse_pktdata(int param_1,int *param_2,int *param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((((param_1 == 0) || (param_2 == (int *)0x0)) || (param_3 == (int *)0x0)) ||
     (param_4 == (int *)0x0)) {
    uVar1 = 0xffffffff;
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : input param invalid\n",
             "_sensor_di_collect_pkt_stat_data_parse_pktdata",0x27c);
    }
  }
  else {
    *param_2 = 0;
    param_2[1] = 0;
    *param_3 = 0;
    param_3[1] = 0;
    *param_4 = 0;
    param_4[1] = 0;
    uVar1 = json_object_object_get(param_1,&DAT_006aa2a8);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_2 + 2);
    if (iVar2 == 0) {
      *param_2 = *param_2 + param_2[2];
      param_2[1] = param_2[1] + param_2[3];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa2b0);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_2 + 4);
    if (iVar2 == 0) {
      *param_2 = *param_2 + param_2[4];
      param_2[1] = param_2[1] + param_2[5];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa2b8);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_2 + 6);
    if (iVar2 == 0) {
      *param_2 = *param_2 + param_2[6];
      param_2[1] = param_2[1] + param_2[7];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa2c0);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_2 + 8);
    if (iVar2 == 0) {
      *param_2 = *param_2 + param_2[8];
      param_2[1] = param_2[1] + param_2[9];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa2c8);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_2 + 10);
    if (iVar2 == 0) {
      *param_2 = *param_2 + param_2[10];
      param_2[1] = param_2[1] + param_2[0xb];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa2d0);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_2 + 0xc);
    if (iVar2 == 0) {
      *param_2 = *param_2 + param_2[0xc];
      param_2[1] = param_2[1] + param_2[0xd];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa2d8);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_2 + 0xe);
    if (iVar2 == 0) {
      *param_2 = *param_2 + param_2[0xe];
      param_2[1] = param_2[1] + param_2[0xf];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa2e0);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_2 + 0x10);
    if (iVar2 == 0) {
      *param_2 = *param_2 + param_2[0x10];
      param_2[1] = param_2[1] + param_2[0x11];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa2e8);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_2 + 0x12);
    if (iVar2 == 0) {
      *param_2 = *param_2 + param_2[0x12];
      param_2[1] = param_2[1] + param_2[0x13];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa2f0);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_2 + 0x14);
    if (iVar2 == 0) {
      *param_2 = *param_2 + param_2[0x14];
      param_2[1] = param_2[1] + param_2[0x15];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa2f8);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_2 + 0x16);
    if (iVar2 == 0) {
      *param_2 = *param_2 + param_2[0x16];
      param_2[1] = param_2[1] + param_2[0x17];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa300);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_3 + 2);
    if (iVar2 == 0) {
      *param_3 = *param_3 + param_3[2];
      param_3[1] = param_3[1] + param_3[3];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa308);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_3 + 4);
    if (iVar2 == 0) {
      *param_3 = *param_3 + param_3[4];
      param_3[1] = param_3[1] + param_3[5];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa310);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_3 + 6);
    if (iVar2 == 0) {
      *param_3 = *param_3 + param_3[6];
      param_3[1] = param_3[1] + param_3[7];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa318);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_3 + 8);
    if (iVar2 == 0) {
      *param_3 = *param_3 + param_3[8];
      param_3[1] = param_3[1] + param_3[9];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa320);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_3 + 10);
    if (iVar2 == 0) {
      *param_3 = *param_3 + param_3[10];
      param_3[1] = param_3[1] + param_3[0xb];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa328);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_3 + 0xc);
    if (iVar2 == 0) {
      *param_3 = *param_3 + param_3[0xc];
      param_3[1] = param_3[1] + param_3[0xd];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa330);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_4 + 2);
    if (iVar2 == 0) {
      *param_4 = *param_4 + param_4[2];
      param_4[1] = param_4[1] + param_4[3];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa338);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_4 + 4);
    if (iVar2 == 0) {
      *param_4 = *param_4 + param_4[4];
      param_4[1] = param_4[1] + param_4[5];
    }
    uVar1 = json_object_object_get(param_1,&DAT_006aa340);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar1,param_4 + 6);
    if (iVar2 == 0) {
      *param_4 = *param_4 + param_4[6];
      param_4[1] = param_4[1] + param_4[7];
    }
    uVar1 = 0;
    uVar3 = json_object_object_get(param_1,&DAT_006aa348);
    iVar2 = _sensor_di_collect_pkt_stat_data_parse_subpktdata(uVar3,param_4 + 8);
    if (iVar2 == 0) {
      *param_4 = *param_4 + param_4[8];
      param_4[1] = param_4[1] + param_4[9];
    }
  }
  return uVar1;
}

