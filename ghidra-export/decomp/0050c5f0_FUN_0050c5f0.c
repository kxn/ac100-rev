// func FUN_0050c5f0 @ 0050c5f0 size=688

undefined4 FUN_0050c5f0(char *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  size_t sVar5;
  time_t tVar6;
  char *pcVar7;
  int local_170;
  char acStack_16c [32];
  tm tStack_14c;
  char acStack_120 [260];
  
  memset(acStack_16c,0,0x1e);
  memset(&tStack_14c,0,0x2c);
  if (param_1 == (char *)0x0) {
    uVar2 = 0xffffffff;
    if (ac_passthrough_err_switch != '\0') {
      printf("[AC_PASSTHROUGH_ERROR]%s()/%d Input error\n","_ac_passthrough_time_json_generate",
             0x856);
    }
  }
  else {
    iVar1 = json_object_new_object();
    uVar2 = json_object_new_object();
    uVar3 = json_object_new_object();
    if (param_2 == 0) {
      uVar4 = json_object_new_string("set");
      json_object_object_add(iVar1,"method",uVar4);
      uVar4 = json_object_new_string("manual");
      json_object_object_add(uVar3,"type",uVar4);
      pcVar7 = "time_type";
    }
    else {
      uVar4 = json_object_new_string(&DAT_00697f28);
      json_object_object_add(iVar1,"method",uVar4);
      tVar6 = time((time_t *)0x0);
      local_170 = tVar6 + 1;
      localtime_r(&local_170,&tStack_14c);
      snprintf(acStack_16c,0x1e,"%04d/%02d/%02d",tStack_14c.tm_year + 0x76c,tStack_14c.tm_mon + 1,
               tStack_14c.tm_mday);
      uVar4 = json_object_new_string(acStack_16c);
      json_object_object_add(uVar3,"date",uVar4);
      memset(acStack_120,0,0x100);
      mktime(&tStack_14c);
      snprintf(acStack_120,0x100,"%lld");
      uVar4 = json_object_new_string(acStack_120);
      json_object_object_add(uVar3,"time",uVar4);
      pcVar7 = "set_time";
    }
    json_object_object_add(uVar2,pcVar7,uVar3);
    json_object_object_add(iVar1,"system",uVar2);
    pcVar7 = (char *)json_object_to_json_string_ext(iVar1,0);
    sVar5 = strlen(pcVar7);
    if (sVar5 < 0x400) {
      strcpy(param_1,pcVar7);
      uVar2 = 0;
      if (ac_passthrough_debug_switch != '\0') {
        printf("[AC_PASSTHROUGH_DEBUG]%s()/%d time json str: %s\n",
               "_ac_passthrough_time_json_generate",0x87c,param_1);
      }
    }
    else {
      uVar2 = 0xffffffff;
      if (ac_passthrough_err_switch != '\0') {
        printf("[AC_PASSTHROUGH_ERROR]%s()/%d Json is too long\n",
               "_ac_passthrough_time_json_generate",0x878);
      }
    }
    if (iVar1 != 0) {
      json_object_put(iVar1);
    }
  }
  return uVar2;
}

