static void swap(t_node **stack)
{
    t_node *first;
    t_node *second;

    if(!stack || !*stack || !*stack -> next)
        return;
    first = *stack;
    second = first -> next;
    first -> next = second -> next;
    second -> next = first;
    *stack = second;
}
static void push(t_node **src, t_node**dest)
{
    t_node *a;

      if(!src || !*src || !dest )
        return;
    a = *src;
    *src = (*src)->next;
    a -> next = *dest;
    *dest = a;
}
static void rotate(t_node **stack)
{
    t_node *first;
    t_node *last;

    if(!stack || !*stack || !*stack -> next)
        return;
    first = *stack;
    *stack = first-> next;
    last = *stack;
    first -> next = NULL;
    while(last-> next)
        last = last -> next;
    last -> next = first;
}
static void rev_rot(t_node **stack)
{
    t_node *prev;
    t_node *last;
    if(!stack || !*stack || !*stack -> next)
        return;
  
    prev = NULL;
    last = *stack;
    while(last -> next)
    {
        prev = last;
        last = last -> next;
    }
    prev -> next= NULL;
    last -> next = *stack;
    *stack = last;
}
