#include "../push_swap.h"

int find_previous(t_node_list *list, int value)
{
    t_node_list *temp = list;
    int previous = -1;

    while (temp)
    {
        if (temp->number < value && (previous == -1 || temp->number > previous))
            previous = temp->number;
        temp = temp->next;
    }
    return previous;
}

int find_next(t_node_list *list, int value)
{
    t_node_list *temp = list;
    int next = -1;

    while (temp)
    {
        if (temp->number > value && (next == -1 || temp->number < next))
            next = temp->number;
        temp = temp->next;
    }
    return next;
}

int rotations_to_value(t_node_list *list, int value)
{
    t_node_list *temp = list;
    int rotations_up = 0;
    int rotations_down = 0;

    while (temp && temp->number != value)
    {
        temp = temp->next;
        rotations_up++;
    }

    temp = list;
    while (temp && temp->number != value)
    {
        temp = temp->previou;
        rotations_down--;
    }

    if (abs(rotations_up) <= abs(rotations_down))
        return rotations_up;
    return rotations_down;
}

int rotations_to_previous(t_node_list *list, int value)
{
    int previous = find_previous(list, value);
    if (previous == -1)
        return 0;
    return rotations_to_value(list, previous);
}

int rotations_to_next(t_node_list *list, int value)
{
    int next = find_next(list, value);
    if (next == -1)
        return 0;
    return rotations_to_value(list, next);
}