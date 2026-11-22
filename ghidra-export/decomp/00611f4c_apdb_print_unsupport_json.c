// func apdb_print_unsupport_json @ 00611f4c size=148

void apdb_print_unsupport_json(void)

{
  char *pcVar1;
  
  if (unsupport_ap_root == 0) {
    pcVar1 = "Not exist json in mem!!";
  }
  else {
    printf("Unrecognize ap: %d\n",unrecognize_ap);
    pcVar1 = (char *)cJSON_Print(unsupport_ap_root);
    if (pcVar1 != (char *)0x0) {
      puts("************************Unsupport ap list*******************************");
      puts(pcVar1);
      puts("*************************************************************************");
      free(pcVar1);
      return;
    }
    pcVar1 = "Not exist unsupport ap in mem!!";
  }
  puts(pcVar1);
  return;
}

