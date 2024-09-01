import java.util.List;

public class Meeting {
    public int end;
    public int start;
    int id;
    List<Attendee> attendeeList;
    Room room;


    public Meeting(int start, int end, List<Attendee> attendeeList,Room room) {
        this.attendeeList = attendeeList;
        this.end = end;
        this.start = start;
        this.id = 1;
        this.room = room;
    }

    @Override
    public String toString(){
        System.out.println(room.id + " and attendee are:");
        for (Attendee attendee : attendeeList){
            System.out.println("Person: " + attendee.name);
        }
        return "start: " + start + " end: " + end;
    }
}
