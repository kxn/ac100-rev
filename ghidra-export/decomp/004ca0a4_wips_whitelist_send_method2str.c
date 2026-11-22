// func wips_whitelist_send_method2str @ 004ca0a4 size=68

char * wips_whitelist_send_method2str(int param_1)

{
  if (param_1 == 0) {
    return "add_white_list";
  }
  if (param_1 != 1) {
    if (param_1 == 2) {
      return "del_white_list";
    }
    return "";
  }
  return "set_white_list";
}

