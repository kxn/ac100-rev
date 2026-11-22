// func local_uac_nms_notify_handle @ 0049d744 size=500

void local_uac_nms_notify_handle(uint param_1,char *param_2,int param_3)

{
  void *__s;
  size_t sVar1;
  void *__s_00;
  char *pcVar2;
  int iVar3;
  char *__s_01;
  char *__s_02;
  
  __s = (void *)FUN_00408450(0x14,0x36b);
  if (__s == (void *)0x0) {
    return;
  }
  if (param_1 < 8) {
    memset(__s,0,0x14);
    __s_02 = (&PTR_s___s_request_info____method___do__0069ca44)[param_1];
    *(uint *)((int)__s + 0xc) = param_1;
    if ((__s_02 != (char *)0x0) && (sVar1 = strlen(__s_02), 0 < (int)sVar1)) {
      iVar3 = sVar1 + 1;
      if (param_2 != (char *)0x0) {
        sVar1 = strlen(param_2);
        iVar3 = sVar1 + iVar3;
      }
      __s_01 = (&PTR_s_all_0069ca64)[param_1];
      sVar1 = strlen(__s_01);
      sVar1 = iVar3 + sVar1;
      __s_00 = (void *)FUN_00408450(sVar1,900);
      *(void **)((int)__s + 0x10) = __s_00;
      if (__s_00 == (void *)0x0) goto LAB_0049d794;
      memset(__s_00,0,sVar1);
      if (param_2 == (char *)0x0) {
        if (param_3 == 1) {
          pcVar2 = "Led on";
        }
        else {
          pcVar2 = "Led off";
        }
        pcVar2 = pcVar2 + 4;
        param_2 = "";
      }
      else if (param_3 == 1) {
        pcVar2 = "on";
      }
      else {
        pcVar2 = "off";
      }
      snprintf(*(char **)((int)__s + 0x10),sVar1,__s_02,param_2,__s_01,pcVar2);
    }
    FUN_004082d0(uac_nms_msg_report_mutex,0xffffffff);
    FUN_004086b0(&g_uac_nms_msg_report_list,__s);
    FUN_004084b0(uac_nms_msg_report_cond);
    FUN_00407f30(uac_nms_msg_report_mutex);
    return;
  }
LAB_0049d794:
  FUN_00407df0(__s);
  return;
}

