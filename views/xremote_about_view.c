/*!
 *  @file flipper-xremote/views/xremote_about_view.c
    @license This project is released under the GNU GPLv3 License
 *  @copyright (c) 2023 Sandro Kalatozishvili
 *
 * @brief View functionality for version and additional information.
 */

#include "xremote_about_view.h"
#include "../xremote.h"

static void xremote_about_view_draw_vertical(Canvas* canvas, XRemoteViewModel* model) {
    UNUSED(model);
    char version[32];

    canvas_set_font(canvas, FontSecondary);
    xremote_get_version(version, sizeof(version));

    canvas_draw_str_aligned(canvas, 0, 30, AlignLeft, AlignTop, "Version:");
    canvas_draw_str_aligned(canvas, 35, 30, AlignLeft, AlignTop, version);

    canvas_draw_str_aligned(canvas, 0, 40, AlignLeft, AlignTop, "License: GPLv3");

    canvas_draw_str_aligned(canvas, 0, 55, AlignLeft, AlignTop, "Original creator:");
    canvas_draw_str_aligned(canvas, 0, 65, AlignLeft, AlignTop, "Sandro Kalatozishvili");

    canvas_draw_str_aligned(canvas, 0, 80, AlignLeft, AlignTop, "External module");
    canvas_draw_str_aligned(canvas, 0, 90, AlignLeft, AlignTop, "revisions:");
    canvas_draw_str_aligned(canvas, 0, 100, AlignLeft, AlignTop, "AzureSky Fable 5.1");
}

static void xremote_about_view_draw_horizontal(Canvas* canvas, XRemoteViewModel* model) {
    UNUSED(model);
    char version[32];

    canvas_set_font(canvas, FontSecondary);
    xremote_get_version(version, sizeof(version));

    canvas_draw_str_aligned(canvas, 0, 0, AlignLeft, AlignTop, "Version:");
    canvas_draw_str_aligned(canvas, 35, 0, AlignLeft, AlignTop, version);

    canvas_draw_str_aligned(canvas, 0, 10, AlignLeft, AlignTop, "License: GPLv3");

    canvas_draw_str_aligned(canvas, 0, 24, AlignLeft, AlignTop, "Original creator:");
    canvas_draw_str_aligned(canvas, 0, 34, AlignLeft, AlignTop, "Sandro Kalatozishvili");

    canvas_draw_str_aligned(canvas, 0, 48, AlignLeft, AlignTop, "External module revisions:");
    canvas_draw_str_aligned(canvas, 0, 58, AlignLeft, AlignTop, "AzureSky Fable 5.1");
}

static void xremote_about_view_draw_callback(Canvas* canvas, void* context) {
    furi_assert(context);
    XRemoteViewModel* model = context;
    XRemoteAppContext* app_ctx = model->context;
    XRemoteViewDrawFunction xremote_about_view_draw_body;

    ViewOrientation orientation = app_ctx->app_settings->orientation;
    xremote_about_view_draw_body = orientation == ViewOrientationVertical ?
                                       xremote_about_view_draw_vertical :
                                       xremote_about_view_draw_horizontal;

    xremote_canvas_draw_header(canvas, orientation, "About");
    xremote_about_view_draw_body(canvas, model);
    xremote_canvas_draw_exit_footer(canvas, orientation, "Press to exit");
}

XRemoteView* xremote_about_view_alloc(void* app_ctx) {
    XRemoteView* view = xremote_view_alloc(app_ctx, NULL, xremote_about_view_draw_callback);

    with_view_model(
        xremote_view_get_view(view), XRemoteViewModel * model, { model->context = app_ctx; }, true);

    return view;
}
