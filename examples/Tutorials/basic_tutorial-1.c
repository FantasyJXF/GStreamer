#include <gst/gst.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;

    gst_init(&argc, &argv);

    //pipeline = gst_parse_launch("playbin uri=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm",  NULL);
    // 在file:// 之后添加文件的路径
    pipeline = gst_parse_launch("playbin uri=file:///home/fantasy/Downloads/hongkong.mp4", NULL);

    gst_element_set_state(pipeline, GST_STATE_PLAYING);

    bus = gst_element_get_bus(pipeline);

    // Wait until error or EOS
    msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

    printf("the msg.timestamp is %lu", msg->timestamp);
    if(msg != NULL)
    {
        gst_message_unref(msg);
    }

    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);

    return 0;
}