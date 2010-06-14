/* Interface for stack switching. */

/* A saved stack frame is completely defined by a pointer to the top of the
 * stack frame. */
typedef void *frame_t;

typedef void (*frame_action_t)(void *arg, void *context);

/* Switch to new frame, previously established by create_frame() or an earlier
 * switch_frame().  The frame context is updated. */
void * switch_frame(frame_t *old_frame, frame_t new_frame, void *arg);

/* Establish a new frame in the given stack.  action(context) will be called
 * when the newly created frame is switched to.  When the action routine returns
 * control is switched to parent. */
void create_frame(
    frame_t *frame, void *stack, size_t stack_size,
    frame_action_t action, void *context);
