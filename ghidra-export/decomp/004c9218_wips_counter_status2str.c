// func wips_counter_status2str @ 004c9218 size=52

char * wips_counter_status2str(int param_1)

{
  if (param_1 == 1) {
    return "on";
  }
  if (param_1 == 2) {
    return "off";
  }
  return "---";
}

