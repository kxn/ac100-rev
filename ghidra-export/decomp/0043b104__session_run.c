// func _session_run @ 0043b104 size=1

undefined4 _session_run(undefined4 *param_1)

{
  __suseconds_t _Var1;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  tm *__tp;
  FILE *__s;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  char *pcVar10;
  char *pcStack_c8b8;
  char *pcStack_c8b4;
  timeval tStack_c8b0;
  char acStack_c8a8 [24];
  char acStack_c890 [31];
  char acStack_c871 [65];
  char acStack_c830 [51208];
  
  memset(acStack_c830,0,0xc801);
  if (param_1[1] == 0) {
    snprintf(acStack_c830,0xc801,
             "GET https://%s/cgi-bin/token?grant_type=client_credential&appid=%s&secret=%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; rv:39.0) Gecko/20100101 Firefox/39.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3\r\nAccept-Encoding: gzip, deflate\r\nCookie: pgv_pvi=9402115072; pgv_si=s8000090112\r\nConnection: keep-alive\r\nCache-Control: max-age=0\r\n\r\n"
             ,g_wechat_config + 0xc4,g_wechat_config + 4,g_wechat_config + 0x44,
             g_wechat_config + 0xc4);
  }
  else {
    if (param_1[1] != 1) {
      return 0xffffffff;
    }
    snprintf(acStack_c830,0xc801,
             "GET https://%s/cgi-bin/getcallbackip?access_token=%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; rv:39.0) Gecko/20100101 Firefox/39.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3\r\nAccept-Encoding: gzip, deflate\r\nCookie: pgv_pvi=9402115072; pgv_si=s8000090112\r\nConnection: keep-alive\r\n\r\n"
             ,g_wechat_config + 0xc4,param_1 + 5,g_wechat_config + 0xc4);
  }
  uVar9 = *param_1;
  pcVar6 = acStack_c830;
  sVar2 = strlen(acStack_c830);
  if ((int)sVar2 < 1) {
    iVar8 = 0;
  }
  else {
    do {
      iVar8 = func_0x00406f40(uVar9,pcVar6,sVar2);
      sVar2 = sVar2 - iVar8;
      if (iVar8 < 0) {
        return 0xffffffff;
      }
      pcVar6 = pcVar6 + iVar8;
    } while (0 < (int)sVar2);
    iVar8 = 0;
  }
  while (iVar3 = func_0x004073f0(*param_1,acStack_c830 + iVar8,0x400), iVar3 == 0x400) {
    iVar8 = iVar8 + 0x400;
  }
  if (iVar3 < 0) {
    return 0xffffffff;
  }
  iVar8 = iVar8 + iVar3;
  if (iVar8 == 0) {
    return 0xffffffff;
  }
  if (0xc800 < iVar8) {
    return 0xffffffff;
  }
  pcVar6 = acStack_c830;
  param_1[2] = 0;
  pcVar10 = pcVar6 + iVar8;
  acStack_c830[iVar8] = '\0';
LAB_0043b234:
  do {
    if (pcVar10 <= pcVar6) {
      iVar8 = param_1[4];
LAB_0043b490:
      if (iVar8 == 0) {
        return 0;
      }
      return 0xffffffff;
    }
    iVar8 = param_1[2];
    if (iVar8 == 0) break;
    iVar3 = (int)pcVar10 - (int)pcVar6;
    if (iVar8 == 1) {
      tStack_c8b0.tv_sec = 0;
      iVar5 = 0;
      tStack_c8b0.tv_usec = 0;
      iVar8 = 0;
      while (((_Var1 = tStack_c8b0.tv_usec, iVar5 < iVar3 && (iVar8 < 2)) && (*pcVar6 != '\0'))) {
        iVar5 = iVar5 + 1;
        if (*pcVar6 == '\"') {
          (&tStack_c8b0.tv_sec)[iVar8] = (__time_t)pcVar6;
          pcVar6 = pcVar6 + 1;
          iVar8 = iVar8 + 1;
        }
        else {
          pcVar6 = pcVar6 + 1;
        }
      }
      if (((tStack_c8b0.tv_sec == 0) ||
          (iVar8 = tStack_c8b0.tv_usec - tStack_c8b0.tv_sec, tStack_c8b0.tv_usec == 0)) ||
         (0x40 < iVar8)) {
        return 0xffffffff;
      }
      memcpy(acStack_c871 + 1,(void *)(tStack_c8b0.tv_sec + 1),iVar8 - 1);
      iVar3 = 6;
      acStack_c871[iVar8] = '\0';
      iVar8 = 0;
      do {
        iVar5 = strcmp(acStack_c871 + 1,(&l_ucWportal_attrPattern)[iVar8]);
        if (iVar5 == 0) break;
        iVar3 = iVar3 + -1;
        iVar8 = iVar8 + 1;
      } while (iVar3 != 0);
      if (iVar8 == 6) {
        DAT_0075a2e8 = iVar8;
        return 0xffffffff;
      }
      pcVar6 = (char *)(_Var1 + 2);
      DAT_0075a2e8 = iVar8;
      param_1[2] = 2;
      goto LAB_0043b234;
    }
    if (iVar8 == 2) {
      iVar3 = (int)pcVar10 - (int)pcVar6;
      pcStack_c8b4 = (char *)0x0;
      iVar8 = -1;
      switch(DAT_0075a2e8) {
      case 0:
        puVar7 = param_1 + 5;
        uVar9 = 0x201;
        goto LAB_0043b4e4;
      case 1:
        puVar7 = param_1 + 3;
        goto LAB_0043b4f8;
      case 2:
        puVar7 = param_1 + 4;
LAB_0043b4f8:
        iVar8 = _pkt_getNumber(pcVar6,iVar3,puVar7,&pcStack_c8b4);
        break;
      case 3:
        puVar7 = (undefined4 *)((int)param_1 + 0x215);
        uVar9 = 0x40;
LAB_0043b4e4:
        iVar8 = _pkt_getStr(pcVar6,iVar3,puVar7,uVar9,&pcStack_c8b4);
        break;
      case 4:
        pcStack_c8b8 = pcVar6;
        while (pcStack_c8b8 < pcVar6 + iVar3) {
          if (*pcStack_c8b8 == ']') {
            pcStack_c8b4 = pcStack_c8b8 + 1;
            break;
          }
          iVar8 = (int)(pcVar6 + iVar3) - (int)pcStack_c8b8;
          if ((iVar8 < 7) ||
             (iVar8 = _pkt_getStr(pcStack_c8b8,iVar8,acStack_c890,0x20,&pcStack_c8b8), iVar8 != 0))
          break;
          strcat(acStack_c890,",");
          sVar2 = strlen(acStack_c890);
          iVar8 = sVar2 + l_ucWportal_fileOffset;
          if (0xc800 < iVar8 + 0x15U) {
            iVar8 = -1;
            goto switchD_0043b2ec_default;
          }
          memcpy(&l_ucWportal_filebuff + l_ucWportal_fileOffset,acStack_c890,sVar2);
          l_ucWportal_fileOffset = iVar8;
        }
        l_ucWportal_fileOffset = l_ucWportal_fileOffset + -1;
        gettimeofday(&tStack_c8b0,(__timezone_ptr_t)0x0);
        __tp = gmtime(&tStack_c8b0.tv_sec);
        strftime(acStack_c8a8,0x15,"|%Y-%m-%d %H:%M:%S",__tp);
        iVar8 = l_ucWportal_fileOffset;
        sVar2 = strlen(acStack_c8a8);
        memcpy(&l_ucWportal_filebuff + iVar8,acStack_c8a8,sVar2);
        sVar2 = strlen(acStack_c8a8);
        l_ucWportal_fileOffset = sVar2 + iVar8;
        __s = fopen("/etc/config/ac_wechatIpList.conf","w+");
        if (__s == (FILE *)0x0) {
          l_ucWportal_fileOffset = 0;
        }
        else {
          sVar2 = fwrite(&l_ucWportal_filebuff,l_ucWportal_fileOffset,1,__s);
          if (-1 < (int)sVar2) {
            fclose(__s);
            (&l_ucWportal_filebuff)[iVar8] = 0;
            l_ucWportal_fileOffset = 0;
            l_ucWportal_IpListUpdateLastTime = tStack_c8b0.tv_sec;
            DAT_00766b28 = tStack_c8b0.tv_usec;
            wportal_update_wechatlist_to_ap(&l_ucWportal_filebuff,iVar8 + 1);
            iVar8 = 0;
            pcStack_c8b4 = pcStack_c8b8;
            break;
          }
          l_ucWportal_fileOffset = 0;
          fclose(__s);
        }
        iVar8 = -1;
        pcStack_c8b4 = pcStack_c8b8;
        break;
      case 5:
        pcStack_c8b4 = strchr(pcVar6,0x5d);
        iVar8 = -1;
        if (pcStack_c8b4 != (char *)0x0) {
          pcStack_c8b4 = pcStack_c8b4 + 1;
          iVar8 = 0;
        }
      }
switchD_0043b2ec_default:
      if (iVar8 != 0) {
        return 0xffffffff;
      }
      if (DAT_0075a2e8 == 4) {
        iVar8 = param_1[4];
        goto LAB_0043b490;
      }
      pcVar6 = pcStack_c8b4 + 1;
      param_1[2] = 1;
    }
  } while( true );
  pcVar4 = strstr(acStack_c830,"\r\n\r\n");
  pcVar6 = pcVar4 + 4;
  if (pcVar4 == (char *)0x0) {
    return 0xffffffff;
  }
  if (pcVar6 == (char *)0x0) {
    return 0xffffffff;
  }
  param_1[2] = 1;
  goto LAB_0043b234;
}

