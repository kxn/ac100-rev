// func test_report_nms_params @ 004a25cc size=908

undefined4 test_report_nms_params(int *param_1)

{
  char *__src;
  size_t sVar1;
  int iVar2;
  FILE *__stream;
  void *__s;
  void *__s_00;
  int iVar3;
  undefined4 extraout_v1;
  undefined4 uVar4;
  size_t __n;
  int iVar5;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar5 = *param_1;
  if (g_test_send_params == (char *)0x0) {
    g_test_send_params = (char *)FUN_00408450(0x32000,600);
    memset(g_test_send_params,0,0x32000);
  }
  do {
    iVar2 = access("/tmp/test_ap_passthrough_params.txt",0);
    __src = g_test_send_params;
    if (iVar2 == 0) {
      if (*g_test_send_params == '\0') {
        __stream = fopen("/tmp/test_ap_passthrough_params.txt","rb");
        if (__stream != (FILE *)0x0) {
          fread(g_test_send_params,0x32000,1,__stream);
          fclose(__stream);
        }
      }
      else if ((((-1 < iVar5) &&
                (((sVar1 = strlen(g_test_send_params), g_fit_ap_dev_params_test == 1 ||
                  (iVar2 = get_uac_nms_report_switch(), iVar2 == 1)) &&
                 (iVar2 = get_nms_support_switch(), iVar2 == 1)))) &&
               (((iVar2 = test_get_fit_ap_ignore_nms_ap_check(), iVar2 == 1 ||
                 (iVar2 = cloud_mngt_ap_is_nms_spupport(iVar5,0), iVar2 == 1)) &&
                (__n = sVar1 + 1, (int)__n < 0x500000)))) && (0 < (int)__n)) {
        __s = (void *)FUN_00408450(0x24,0x20e);
        if (__s == (void *)0x0) {
          if (cloud_mngt_err_switch != '\0') {
            uVar4 = 0x211;
LAB_004a2894:
            printf("[CLOUD_MNGT_ERROR]%s()/%d no memory to alloc!!!\n",
                   "test_uac_nms_params_report_request",uVar4);
          }
        }
        else {
          g_test_stats_len = g_test_stats_len + __n;
          g_test_stats_count = g_test_stats_count + 1;
          memset(__s,0,0x24);
          *(int *)((int)__s + 0xc) = iVar5;
          *(size_t *)((int)__s + 0x1c) = __n;
          __s_00 = (void *)FUN_00408450(sVar1 + 2,0x21f);
          *(void **)((int)__s + 0x20) = __s_00;
          if (__s_00 == (void *)0x0) {
            FUN_00407df0(__s);
            if (cloud_mngt_err_switch != '\0') {
              uVar4 = 0x223;
              goto LAB_004a2894;
            }
          }
          else {
            memset(__s_00,0,*(int *)((int)__s + 0x1c) + 1);
            memcpy(*(void **)((int)__s + 0x20),__src,__n);
            FUN_004082d0(uac_nms_params_report_mutex,0xffffffff);
            if (__n + g_total_fit_nms_params_cnt < 0x500000) {
              *(undefined1 *)((int)__s + 0x10) = 0;
            }
            else {
              if (g_test_stats_debug != 0) {
                printf("g_total_fit_nms_params_cnt:%d tmp_len:%d g_test_stats_len:%d g_test_stats_count:%d.\r\n"
                       ,g_total_fit_nms_params_cnt,__n,g_test_stats_len,g_test_stats_count);
              }
              iVar2 = g_total_fit_nms_params_cnt;
              iVar3 = replace_old_uac_nms_params_report(__n,&g_uac_nms_params_report_list);
              g_total_fit_nms_params_cnt = iVar2 - iVar3;
              *(undefined1 *)((int)__s + 0x10) = 0;
            }
            *(undefined1 *)((int)__s + 0x11) = 0;
            FUN_00407e70();
            *(undefined4 *)((int)__s + 0x14) = extraout_v1;
            FUN_004086b0(&g_uac_nms_params_report_list,__s);
            g_total_fit_nms_params_cnt = __n + g_total_fit_nms_params_cnt;
            FUN_00407f30(uac_nms_params_report_mutex);
            if (g_total_fit_nms_params_cnt * 100 < 0x1c200000) {
              _uac_nms_cancle_send_later_handle(2);
            }
            else {
              _uac_nms_trigger_send_later_handle();
            }
            uac_nms_params_report_by_receive_data();
          }
        }
      }
    }
    usleep(g_test_params_report_interval * 1000);
  } while( true );
}

