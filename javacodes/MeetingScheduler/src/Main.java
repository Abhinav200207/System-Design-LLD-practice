import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Room r1 = new Room(1);
        Room r2 = new Room(2);
        Room r3 = new Room(3);
        Room r4 = new Room(4);
        Room r5 = new Room(5);
        List<Room> rooms = new ArrayList<>();
        rooms.add(r1);
        rooms.add(r2);
        rooms.add(r3);
        rooms.add(r4);
        rooms.add(r5);
        MeetingManager meetingManager = new MeetingManager(rooms);

        Attendee a1 = new Attendee("Abhinav");
        Attendee a2 = new Attendee("Kumar");
        Attendee a3 = new Attendee("Maurya");
        Attendee a4 = new Attendee("Booby");
        Attendee a5 = new Attendee("Gold");
        Attendee a6 = new Attendee("Himanshu");
        Attendee a7 = new Attendee("Singh");

        Meeting meeting = meetingManager.scheduleMeeting(1,3,List.of(a1,a2,a3));
        System.out.println("-----------------");
        Meeting meeting1 = meetingManager.scheduleMeeting(1,3,List.of(a6,a4));

        meeting.toString();
        meeting1.toString();
    }
}