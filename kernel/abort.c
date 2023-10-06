#include <xos/abort.h>
#include <xos/klog.h>

void abort() {
  klog_fatal("abort()");
  while(1) {}
}
